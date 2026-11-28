# PlayerbotV2 localization audit

Audit date: 2026-11-27. Branch `feature/localization`, based on `OxideGer/ForeverCore` `lazy-key-all-classes`
(`646ad8b866`: WoW Forever Bots 0.1.39 plus the lazy-key change). The upstream dev branch `Karrz1/ForeverCore` /
`Karrz1/TrinityCore` `forever-bots` (`69f6f6249c`) has the same locale files (`Api/BotLanguage.*`, `Util/BotLocale*`,
`Addon/ForeverBots/Locale_ruRU.lua`), so everything below holds for both; the dev branch only adds the Hire module and
race/sex RPG first names plus surnames (`Fleet/BotNamePool`, migrations 0063/0064), which this branch does not have yet.

`Karrz1/Karrz-playerbots-wow-forever` is the old, incomplete copy its README says it is and was not used.

All paths below are relative to `src/modules/PlayerbotV2/` unless they start with `src/`, `sql/` or `tests/`.

## 1. Locales of the client and the core

`src/common/Common.h` defines `LOCALE_enUS 0, koKR 1, frFR 2, deDE 3, zhCN 4, zhTW 5, esES 6, esMX 7, ruRU 8, none 9,
ptBR 10, itIT 11`. The ten target locales of the task are all there. `itIT` also exists in the core enum (and the user's
own ForeverGMPanel ships an itIT file), but it is not on the list of WoW Forever client languages the task gives, so it is
**not** added as a bot language: an itIT reader gets English (the documented fallback for any unsupported locale). `enGB`
is not a core locale; the client reports it as enUS to the server, and the add-on already treats it as English.

## 2. How the bots' language works today (the original architecture)

The design is already centralized and recipient-based, which is why it can be extended instead of replaced:

| Piece | File | What it does |
|---|---|---|
| Reader language | `Api/BotLanguage.cpp` `LangOf(Player const*)` | `.bot language` choice (per account) → else session DBC locale → else session DB locale index → else the `account.locale` the client reported at login (async login-DB query in `OnLogin`) → else English. Bots and the console always read English. |
| Stored choice | `playerbot_v2_owner_language` (`sql/playerbot_v2/0038_owner_language.sql`), `language TINYINT UNSIGNED` | 0 auto, 1 en, 2 ru. A plain number, so more languages fit without a schema change. |
| Send points | `Api/BotLanguage.cpp` `Whisper`, `GroupChat`, `SayInRange`, `ChannelSay`, `GuildSay`, `LocalizedHandler` | The only places a bot's text leaves the server. Party/raid/say/channel/guild build **one packet per language** for the readers present (`ChatByLang`, `TextByLang`), so every reader gets their own language with no duplicated game action. |
| Translation | `Util/BotLocaleText.{h,cpp}` `Catalog` | English source line → translation. Exact lines and templates (`{}` `{?}` `{#}` `{$}` `{@}` `{!}`), "Name: rest", "a; b; c" lists, nested captures, money units. Pure code, unit tested. |
| Russian catalog | `Util/BotLocaleRu.cpp` | 1,062 code lines (`RussianEntries`) + 723 stock-chatter lines (`RussianChatterEntries`, keyed on the database text of migration 0019). |
| Model-free conversation | `Bot/BotConversation.cpp` | Intent classifier + reply pools. Has its own Russian reply pools (`PoolsForRu`, `JokesRu`, Russian zone names/routes) selected by `ConversationContext::russian`. |
| Player input understanding | `Bot/PartyTalk.h`, `Bot/GuildAskText.cpp`, `Bot/TradeTalk.h`, `Bot/ChannelTalk.h`, `Bot/GroupOrderText.cpp`, `Bot/GuildWhisperInvite.h`, `Bot/BotCommandParser.cpp` | Keyword lists in English and Russian (a few German words: "wo"). |
| External bridge / chat model | `Bot/BotBridge.cpp` `ReaderLocale`, `MostReadLocale`, `ListenersLocale`; `Bot/BotChatModel*.cpp` | Tells the external program "ruRU" or "enUS"; `Playerbot.ChatModel.Language = auto`. |
| Add-on | `Addon/ForeverBots/Locale_ruRU.lua` (588 keys), `ForeverBots.lua` `L` table | Keyed by English text; missing keys show English. |
| Config | `conf/playerbot.conf.dist` `Playerbot.Language.Enable` | 0 = all English. |

Answers to the task's questions:

1. **Detection**: per reader, from the session / auth account locale (see table). 2. **Stored**: in memory per account,
   the explicit choice in `playerbot_v2_owner_language`. 3. **Selection of Russian**: at the send point, per reader, by
   `Locale::Translate(lang, english)`. 4. **Granularity**: per receiving player (not per bot, not global); only lines
   nobody in particular reads (street talk, General/Trade posts by the external program) use the most-read language of the
   map's players (`ListenersLocale`). 5. **Russian coverage**: every player-facing `.bot` command reply that goes through
   `LocalizedHandler` (19 handlers), bot replies, raid callouts/banter/voice, quest refusals, the stock chatter, the
   conversation pools and the add-on. 6. **English-only on purpose**: GM/diagnostic commands (`.playerbot v2 ...`, `.selftest`,
   about 640 `SendSysMessage` calls in `Commands/cs_playerbot_v2.cpp` / `cs_selftest.cpp`), log lines, `ASSIGN|` add-on lines,
   command words the player types, and the 218 stock-chatter rows that have no Russian line yet. 7. **Duplication**: the
   `Lang` → string switches are repeated in `BotBridge.cpp` (three places), `TextByLang`/`ChatByLang` arrays hard-code 2
   languages, `BotConversation` uses a `bool russian`. 8. **Extendable**: yes; every switch is two-valued and local.

## 3. Inventory of language-dependent sources

| # | Source | Kind | Today | Plan |
|---|---|---|---|---|
| 1 | Code reply lines across `Bot/`, `Api/`, `Fleet/`, `Commands/` (built in English, translated at the send point) | text | ru via catalog | one catalog per language |
| 2 | `sql/playerbot_v2/0019_bot_texts.sql` (941 rows, 175 keys), `0022`, `0041`, `0042` | stock chatter | ru for 723 lines | per-language catalog + native variant pools; **no SQL change** |
| 3 | `Bot/Raid/RaidBanter.h`, `RaidCallouts.h`, `RaidVoice.h`, `Bot/Quest/QuestRefusal.h` | fixed English tables | ru via catalog (tested) | covered by #1 |
| 4 | `Bot/BotConversation.cpp` | own reply pools en + ru | ru native | per-language pools (`Lang` instead of `bool russian`) |
| 5 | `Bot/PartyTalk.h`, `GuildAskText.cpp`, `TradeTalk.h`, `ChannelTalk.h`, `GroupOrderText.cpp`, `GuildWhisperInvite.h` | input keywords | en + ru | add de/fr/es/pt words (Latin script, word-tokenized). Korean/Chinese: only whole-message matches, the tokenizer splits on spaces |
| 6 | `Fleet/BotNamePool.cpp` (`{shared}.playerbots_names`, 107K real first names), `Fleet/BotComposition.cpp` `RollUniqueName` (syllables) | bot names | English-style only | locale name pools in source, drawn before the DB pool |
| 7 | `Fleet/BotGuildNamePool.cpp` (~30 per faction) | bot guild names | English | later stage: per-locale guild names (24-char limit, same validation) |
| 8 | `Bot/BotBridge.cpp` `ReaderLocale` etc. | locale code to the external program | "ruRU"/"enUS" | the reader's real code ("deDE", ...) |
| 9 | `Bot/BotChatReactor.cpp:330,425` | area names `AreaName[LOCALE_ruRU]` | ru only | `AreaName[reader locale]` when the DBC has it |
| 10 | `Addon/ForeverBots/*.lua` | UI strings through `L[...]` | ru | `Locale_<code>.lua` per language, listed in the `.toc` |
| 11 | `Addon/ForeverCombatNameplates`, `Addon/ForeverDots` | SIN's / Karrz's small add-ons | en (+ 4 ru lines) | out of scope for this pass (not bot text) |
| 12 | `Commands/cs_playerbot_v2.cpp` `.bot language auto|en|ru` | command | 3 values | all codes + native names; existing words stay |
| 13 | GM / diagnostic output, logs | text | English on purpose | stays English (operators' tools) |

## 4. Character-name constraints (verified in the core)

`ObjectMgr::CheckPlayerName` and `normalizePlayerName` (`src/server/game/Globals/ObjectMgr.cpp`):

* at most **12 characters** (`MAX_PLAYER_NAME`), at least `MinPlayerName` (default 2);
* **normalized to "First letter upper, rest lower"**: `HauDruff` is stored as `Haudruff`. Pools are written in that form;
* letters of **one script only** (`isValidString`): with `StrictPlayerNames = 0` (the `worldserver.conf.dist` default)
  extended Latin (A–Z, À–þ without ×/÷, Ā–į, ß/ẞ), Cyrillic, Hangul or CJK. No digits, spaces, apostrophes or hyphens;
* no letter three times in a row (case-insensitive);
* the client's `NamesProfanity` / `NamesReserved` DB2 lists (`DB2Manager::ValidateName`, per locale);
* unique (`sCharacterCache`), not reserved (`IsReservedName`).

Consequences: Latin-script pools (en, de, fr, es, mx, pt) may use their accented letters within the Latin range above
(ä ö ü ß é è ê à ç ñ ã õ á í ó ú). `ł`, `ő`, `ű` and similar are outside it and are not used. Korean and Chinese pools
use Hangul / Hanzi, which the core accepts with `StrictPlayerNames = 0` (or a realm charset that includes them). A realm
with `StrictPlayerNames = 1` (basic Latin) or a Latin-only realm charset rejects them; the pool code validates every
candidate with `CheckPlayerName` before use and falls back to the existing pools, so a strict realm never fails a bot
creation. Players on Western clients cannot easily type Hangul/Hanzi names to whisper or invite; this is why Korean and
Chinese pools are only used when the configured name locale is koKR / zhCN / zhTW (see the configuration doc).

A character name is global: one name per bot for every reader, so names follow one server-wide setting, never the reader.

## 5. Gaps found

* `Lang` has two values; arrays sized 2 in `ChatByLang`/`TextByLang`; `Pref` has three; `ParsePref` knows en/ru only.
* No server-wide default language for lines that have no single reader, and none for new bot names.
* Names: all pools are English-style (real English first names or syllables); nothing locale-aware.
* `BotConversation` is two-valued (`bool russian`).
* Input keywords understand en/ru only.
* The add-on has only `Locale_ruRU.lua`.
* `BotRollUniqueName` appends digits as its last fallback, which `CheckPlayerName` always rejects (harmless, it just fails
  late); noted, not changed.

## 6. Changes (implementation stages)

1. **Architecture** (this stage): `Lang` for all ten locales with stable numbers; `LangFromLocale`, `LangCode`, `ParseLang`;
   one catalog per language with a fallback chain (esMX ↔ esES, then English); catalog entries may carry several
   variants, one picked at random per line; `Pref` stored as the same TINYINT; `.bot language` accepts every code;
   bridge locale codes; `Playerbot.Localization.DefaultLocale`; unit tests.
2. **Names**: source-controlled per-locale pools (≥ 200 each), validated at use, drawn before the database pools; config
   `Playerbot.Localization.NameLocale`.
3. **Dialogue**: per-locale catalogs of the stock chatter with native variant pools per situation, `BotConversation`
   pools per language, raid banter/callouts.
4. **Remaining code lines and the add-on**: the 1,062 code lines per language; `Locale_<code>.lua` for the add-on.
5. **Tests and builds**: `-DBUILD_PLAYERBOT_V2=1` with tests, and `=0`.

Coverage per stage is recorded in section 7 as the work lands.

## 7. Implementation coverage

| Stage | State |
|---|---|
| 1 Architecture | done: `Lang` ×10, `LangFromLocale`/`LangCode`/`ParseLang`, per-language catalogs (`Util/BotLocale{De,Fr,EsES,EsMX,PtBR,Ko,ZhCN,ZhTW}.cpp`, empty), variants, esMX↔esES fallback, `Pref` 0–10, `.bot language` all codes, `.playerbot langprobe <locale>`, bridge codes, zone names in the reader's locale, `Playerbot.Localization.DefaultLocale`, tests `tests/game/ClassicBotLocaleLangs.cpp`. See `docs/PLAYERBOT_LOCALIZATION.md`. |
| 2 Names | done: one list per locale (230–271 names each, 2,461 in all) in `Fleet/Names/BotNames*.cpp`, `Fleet/BotLocaleNames` (rules check), `Fleet/BotLocaleNamePicker` (config `Playerbot.Localization.NameLocale`, live `CheckPlayerName`), drawn before the database pools in `BotComposition::Roll`; tests `tests/game/ClassicBotLocaleNames.cpp`. No schema change, no rename of existing characters. itIT is not a WoW Forever client language (checked against the client language list) and is not added. |
| 3 Dialogue | German done: `Util/BotLocaleDeChatter.cpp` (all 100 used chatter keys, 829 lines), `Util/BotLocaleDe.cpp` (all 1,062 code lines, 1,079 entries), German conversation pools / jokes / destinations in `Bot/BotConversation.cpp`, German cue words in `Bot/PartyTalk.h` and `Bot/GuildAskText.cpp`; tests in `ClassicBotLocaleLangs.cpp`, `ClassicBotConversation.cpp`, `ClassicPartyTalk.cpp`, `ClassicGuildAskText.cpp`. Other languages: pending. |
| 4 Code lines, add-on | German code lines done with stage 3; add-on `Locale_deDE.lua` and the other languages pending. |
| 5 Tests, builds | pending |
