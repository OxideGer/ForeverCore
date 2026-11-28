# PlayerbotV2 localization

How the WoW Forever bots speak every client language, and how to extend it. The audit that led to this design is in
`docs/PLAYERBOT_LOCALIZATION_AUDIT.md`.

## Supported locales

| Locale | Language | `Locale::Lang` | `.bot language` word |
|---|---|---|---|
| enUS (enGB) | English | `En` 0 | `en` |
| ruRU | Russian | `Ru` 1 | `ru` |
| deDE | German | `De` 2 | `de` |
| frFR | French | `Fr` 3 | `fr` |
| esES | Spanish (Spain) | `EsES` 4 | `es` |
| esMX | Spanish (Latin America) | `EsMX` 5 | `mx` |
| ptBR | Brazilian Portuguese | `PtBR` 6 | `pt` |
| koKR | Korean | `Ko` 7 | `ko` |
| zhCN | Simplified Chinese | `ZhCN` 8 | `cn` |
| zhTW | Traditional Chinese | `ZhTW` 9 | `tw` |

Any other client locale (itIT, a locale the core does not know) reads English. The numbers are stable: they index the
per-language arrays of the send points, and `language number + 1` is what `playerbot_v2_owner_language.language` stores
(0 = auto, 1 = en, 2 = ru as before; 3 … 10 the new languages). No schema change: the column was already a TINYINT.

`.bot language` also accepts the full codes (`deDE`), English names (`german`) and each language's own name (`deutsch`,
`français`, `español`, `português`, `한국어`, `简体中文`, `繁體中文`, `русский`); "auto" in every language (`automatisch`,
`automatique`, `automático`, `авто`, `자동`, `自动`, `自動`). The words of the old version (`auto|en|ru`, the Russian ones) work as
before.

## Locale detection (per reader)

`Api/BotLanguage.cpp` `LangOf(reader)`, unchanged in order:

1. the player's `.bot language` choice (per account);
2. the session's DBC locale, then its DB locale index, when not enUS;
3. the locale the client reported at login (`account.locale`, read once per login);
4. English.

Bots and the console always read English: their text feeds the bot logic and the logs.

## Architecture

```
bot logic builds an English line
        │
        ▼
send point (Api/BotLanguage.cpp): Whisper / GroupChat / SayInRange / ChannelSay / GuildSay / LocalizedHandler
        │  one packet per language present among the readers (ChatByLang, TextByLang)
        ▼
Locale::Translate(lang, english)        (Util/BotLocaleText.cpp)
        │  1. the reader's catalog          CatalogOf(lang)
        │  2. the sister catalog            esMX ↔ esES
        │  3. English, unchanged
        ▼
the reader's chat frame
```

* **One place decides the language** (`LangOf`), one place translates (`Locale::Translate`). Call sites keep writing
  English; nothing in the bot logic checks a locale.
* **Per recipient**: a party of a German, a French and a Russian player gets three packets of the same line, each in the
  reader's language. The game action behind the line happens once; only the packet is per language, and at most one per
  language present, so the cost is bounded by ten packets whatever the group size.
* **Lines without one reader** (street talk and General/Trade posts written by the external program) use the most-read
  language of the map's real players (`BotBridge.cpp` `MostReadLocale`), or `Playerbot.Localization.DefaultLocale` when no
  player is there.
* **Catalogs** (`Util/BotLocale<Xx>.cpp`): `Entries` (lines the code builds) and `ChatterEntries` (the database stock
  chatter of migration 0019, keyed on the stored text with its `%placeholders`). The template syntax is described at the top
  of `Util/BotLocaleText.h`.
* **Variants**: in every catalog but the Russian one the same English text may appear several times. Each is a variant;
  one is picked at random per line (`PickVariant`, thread-local generator). This is how a language gets its own humor
  instead of one fixed translation per English line. The Russian catalog stays strict (one translation per line; a repeat
  is reported as a typo), so its behaviour is exactly as before.
* **Money** is written with each client's own letters (deDE g/s/k, frFR po/pa/pc, es/pt o/p/c, ruRU з/с/м, koKR 골드/실버/코퍼,
  zhCN 金/银/铜, zhTW 金/銀/銅).
* **Zone names** in bot answers use the reader's locale column of `AreaTable` when the server has that client data, else the
  realm's own.
* **Never translated**: `ASSIGN|` add-on lines (`NeverTranslate`), command words the player types, GM / diagnostic output,
  log lines.

## Dialogue organization

* **Code lines** (`Util/BotLocale<Xx>.cpp`, `Entries`): every line the code builds (replies to orders, raid callouts and banter,
  quest refusals, status lines, LFG and guild chat, short party answers). Keyed by the English text with its captures.
* **Stock chatter** (`Util/BotLocale<Xx>Chatter.cpp`, `ChatterEntries`): the 100 text keys of the database (`playerbot_v2_bot_text`)
  the code actually says: loot, quests, kills, level-ups, LFG / trade / faction posts, random chatter, greetings, the
  reply pools, taunts, low health / mana, AoE and loot calls, question answers, emote answers. Keyed by the database line; a
  German line may say it its own way (several variants, a placeholder left out where it reads better), never adds one.
  The 87 keys the code never says (ike3 leftovers: `quest_status_*`, `cast_spell_command_*`, `use_command_*`, ...) are left out.
* **Conversation** (`Bot/BotConversation.cpp`): intent classification and answers. English, Russian and German have their own
  answer pools (`PoolsForEn/Ru/De`), jokes, ask-backs, repeat answers, destination names and routes; the words a player types
  are recognized in all three.
* **Player chat words** (`Bot/PartyTalk.h`, `Bot/GuildAskText.cpp`): thanks, grats, laugh, wait / go / back / drink cues,
  ready, greetings, guild invite asks: English, Russian and German.

## Fallback behaviour

| Reader | Line in their catalog | Line only in sister catalog | Line nowhere |
|---|---|---|---|
| enUS / unsupported | English | English | English |
| esMX | esMX | esES | English |
| esES | esES | esMX | English |
| others | own | — | English |

A missing or malformed catalog entry never breaks a line: malformed entries are refused at startup (logged as
`[language] <code> catalog entry refused`) and the line goes out in English.

## Configuration

| Key | Default | Meaning |
|---|---|---|
| `Playerbot.Language.Enable` | 1 | 0 = every bot line in English. |
| `Playerbot.Localization.DefaultLocale` | `auto` | Language of lines no single reader decides. `auto` = realm DBCLocale, or a locale code. Unknown values are logged and read as `auto`. |
| `Playerbot.Localization.NameLocale` | `default` | Name list of new bots: `default`, a locale code, `players` or `off` (see Bot names). |

## Bot names

Every client language has its own list of character names, written for that community (not translated from one list):

| List | File | Names | Style |
|---|---|---|---|
| enUS | `Fleet/Names/BotNamesEn.cpp` | 250 | MMO memes, joined-word usernames, class puns |
| deDE | `Fleet/Names/BotNamesDe.cpp` | 271 | puns, food and beer, dialect, fairy tales (Haudruff, Bierfürst, Tankwart, Frostbeule) |
| ruRU | `Fleet/Names/BotNamesRu.cpp` | 265 | Cyrillic; gamer slang and memes, patronymic nicknames, cartoons, folk tales (Нагибатор, Палыч, Пивозавр) |
| frFR | `Fleet/Names/BotNamesFr.cpp` | 255 | race/class puns, French internet slang, cheese, literature (Paladingue, Nainternet, Kikoolol) |
| esES | `Fleet/Names/BotNamesEsES.cpp` | 240 | Spanish gamer slang, cuñado humour, tapas, Golden Age literature (Manco, Cuñao, Croqueta) |
| esMX | `Fleet/Names/BotNamesEsMX.cpp` | 230 | Mexican slang, taquería, lucha libre, Día de Muertos, folklore (Chido, Taquero, Ajolote) |
| ptBR | `Fleet/Names/BotNamesPtBR.cpp` | 235 | Brazilian memes and regional words, boteco food, folklore (Sextou, Coxinha, Saci) |
| koKR | `Fleet/Names/BotNamesKo.cpp` | 245 | Hangul; game slang and memes, food, folk tales (만렙, 치느님, 가즈아) |
| zhCN | `Fleet/Names/BotNamesZhCN.cpp` | 240 | Simplified; WoW CN slang, memes, food, classic novels (奶妈, 摸鱼达人, 法爷) |
| zhTW | `Fleet/Names/BotNamesZhTW.cpp` | 230 | Traditional; Taiwanese slang, PTT memes, night market, folklore (雷包, 半糖少冰, 虎姑婆) |

**Which list** a new bot takes its name from: `Playerbot.Localization.NameLocale`.

| Value | Names of new bots |
|---|---|
| `default` (default) | the language of `Playerbot.Localization.DefaultLocale` (`auto` there = the realm's DBCLocale) |
| `deDE`, `frFR`, … | that list only: `deDE` gives German names only |
| `players` | the client languages of the real players seen since the start, weighted by how many read each one |
| `off` | no list: the database name pools as before this change |

**Rules** (checked by `LocaleNames::FitsCoreRules` and the unit test, and again by the core's `ObjectMgr::CheckPlayerName` before
a name is taken): at most 12 letters, one script, no digits, blanks or signs, no letter three times in a row, written in the
form the core stores (`Haudruff`, not `HauDruff`: the core lower-cases everything after the first letter). Korean and Chinese
names need a realm that allows Hangul / Hanzi (`StrictPlayerNames = 0`, the default); a stricter realm rejects them at the
core's check and the bot gets a database-pool name instead.

**Gender**: each name is tagged male, female or either; a bot only gets a name that fits its gender.

**Used-up lists**: a list has about 250 names. Once every name of a list is taken (by bots or players), new bots fall back to the
database pools and the syllable generator, and the log says so once (`[names] the deDE name list has no free name left`).
Add names to the list to extend it.

**Existing characters are never renamed.** A character name is global and stored in `characters`; only bots created after
this change take names from the lists. Bots that exist keep their names. There is no automatic rename; a server owner who wants
older bots renamed can delete those bots with the existing bot commands and let new ones be created (never touches real
players' characters).

No database change: the lists are source files; the database name pools are not changed.

### Adding names

Add `{ "Name", kMale | kFemale | kAny }` to the language's list in `Fleet/Names/BotNames<Xx>.cpp`, in the stored form. Run the
unit tests: they reject a name the core would refuse, and a name that is already in the same list.

## Adding translations

1. Find the exact English text the code builds (or the database line for stock chatter).
2. Add `{ "english", "translation" }` to `Entries()` (code lines) or `ChatterEntries()` (database lines) of
   `Util/BotLocale<Xx>.cpp`. Use the capture syntax for names, numbers, money and links; keep every capture of the English
   line in a code-line translation. A chatter variant may leave a placeholder out but never add one.
3. More than one entry with the same English text = variants.
4. Check it without a client: `.playerbot langprobe deDE <english line>` on a running server, or the unit tests.

## Adding a language

1. Add the value to `Locale::Lang` before `Count` (never renumber), a row to `kLangs` in `Util/BotLocaleText.cpp` (locale
   number, code, own name, money letters) and its words to `ParseLang`.
2. Add `PrefName`'s short word in `Api/BotLanguage.cpp`.
3. Create `Util/BotLocale<Xx>.cpp` and add it to `Entries`/`ChatterEntries`/`CatalogOf`.
4. Add the add-on file `Addon/ForeverBots/Locale_<code>.lua` and list it in `ForeverBots.toc`.

## Testing

`tests/game/ClassicBotLocale.cpp` (Russian behaviour, unchanged) and `tests/game/ClassicBotLocaleLangs.cpp` (all locales:
mapping, words, catalog well-formedness, UTF-8, placeholders, fallback, variants, money) and
`tests/game/ClassicBotLocaleNames.cpp` (the core's name rules, every list valid, at least 200 names, no repeats, enough names
for both genders, each list in its script). They build with
`-DBUILD_PLAYERBOT_V2=1 -DBUILD_TESTING=1` and run with `tests.exe "[BotLocale]"`.

## Status

| Language | Names | Code lines | Stock chatter | Conversation pools | Player chat words |
|---|---|---|---|---|---|
| enUS | 250 | source text | source text | own | own |
| ruRU | 265 | 1,062 | 723 | own | own |
| deDE | 271 | 1,062 lines (1,079 with variants) | 763 lines (829 with variants) | own (`PoolsForDe`) | party chat, conversation, guild asks |
| frFR, esES, esMX, ptBR, koKR, zhCN, zhTW | 230–255 each | empty (English) | empty (English) | English, translated per catalog | English and Russian only |

German is complete for every text the bots say. The other languages follow in the same structure.

## Known limitations

* Character names are global: one name per bot for all readers, chosen by one server-wide setting.
* Bot guild names (`Fleet/BotGuildNamePool.cpp`) are still English.
* A name handed out for a creation that then failed stays blocked until the next server start.
* Korean and Chinese keyword understanding of player chat is limited: the tokenizer splits on spaces.
* GM and diagnostic commands stay English.
