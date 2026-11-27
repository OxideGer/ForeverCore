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
mapping, words, catalog well-formedness, UTF-8, placeholders, fallback, variants, money). They build with
`-DBUILD_PLAYERBOT_V2=1 -DBUILD_TESTING=1` and run with `tests.exe "[BotLocale]"`.

## Status

This document grows with the stages listed in the audit (names, dialogue, remaining lines, add-on). Stage 1 (architecture)
is in place; the catalogs of the new languages are created and empty until the content stages fill them, so those readers
get English until then, exactly as an unsupported locale does.

## Known limitations

* Character and guild names are global: one name per bot for all readers (see the name stage).
* Korean and Chinese keyword understanding of player chat is limited: the tokenizer splits on spaces.
* GM and diagnostic commands stay English.
