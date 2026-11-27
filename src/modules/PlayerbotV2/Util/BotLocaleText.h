// BotLocaleText - the bots' replies in the player's language (pure: no game objects, unit tested).
//
// A bot builds every reply in English, as it always has. The reply is translated where it leaves the server for one player
// (Api/BotLanguage.cpp: a whisper, a party / raid / say line, a channel or guild line, a `.bot` command reply), so no call site
// changes and a line nobody translated yet still arrives, in English.
//
// A catalog entry is an English template and its translation. In the English template `{}` stands for any non-empty text (a
// name, a number, an item), `{?}` for any text or none (an optional tail such as ", mana 40/90"), `{#}` for a number (digits,
// . - +), `{$}` for an amount of money ("1g 20s 5c"), `{@}` for text holding a chat link (|Hitem:...) and `{!}` for one word
// (a character's name). The translation places the captured texts with `{}` (in the English order) or `{1}`..`{9}` (any
// order). A captured text is translated too when it is itself in the catalog ("pulling Mob to {}" with "the rally point" as the
// capture), or is a comma list of catalog words; money gets the language's own letters.
//
// Lookup, in order: the exact text; the templates, most specific (most fixed letters) first; "<Name>: <rest>" with the rest
// translated (the per-bot confirmations "Rento: following you"); the "; " separated parts of a list line each on their own.
// Anything else comes back unchanged.
//
// Languages: every client language of WoW Forever has a catalog (Util/BotLocale<Xx>.cpp). A line the reader's catalog does not
// know is tried in the sister catalog where there is one (esMX <-> esES), then sent in English. A catalog of a new language may
// give one English line several translations (the same English text in more than one entry): each time the line is sent one
// of them is picked at random, so a German or a French bot does not answer with the one fixed line the English bot has.

#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace Playerbot::Locale {

// The languages a reply can be given in. English is the source text; the others have a catalog. The numbers are stable (they
// index the per-language arrays of the send points); a new language goes at the end, before Count.
enum class Lang : uint8_t
{
    En   = 0,   // enUS (and enGB, which the client reports as enUS)
    Ru   = 1,   // ruRU
    De   = 2,   // deDE
    Fr   = 3,   // frFR
    EsES = 4,   // esES, Spanish of Spain
    EsMX = 5,   // esMX, Latin American Spanish
    PtBR = 6,   // ptBR, Brazilian Portuguese
    Ko   = 7,   // koKR
    ZhCN = 8,   // zhCN, Simplified Chinese
    ZhTW = 9,   // zhTW, Traditional Chinese
    Count
};

constexpr size_t kLangCount = size_t(Lang::Count);

// The language of a client locale, by the core's LocaleConstant number (enUS 0, koKR 1, frFR 2, deDE 3, zhCN 4, zhTW 5, esES 6,
// esMX 7, ruRU 8, ptBR 10). A locale the bots have no language for (itIT 11, none 9, anything out of range) reads English.
Lang LangFromLocale(uint8_t locale);
// The core's LocaleConstant number of a language (enUS 0 ... ptBR 10).
uint8_t LocaleOf(Lang lang);
// "enUS", "ruRU", "deDE", "frFR", "esES", "esMX", "ptBR", "koKR", "zhCN", "zhTW".
char const* LangCode(Lang lang);
// The language's name in itself ("Deutsch", "Français", ...), for the `.bot language` replies.
char const* LangNativeName(Lang lang);
// A locale code ("deDE", "dede", "de-DE", "de_DE"), a short code ("de", "pt", "mx", "kr", "cn", "tw"), an English language name
// ("german") or the language's own name ("deutsch", "français", "español", "한국어", "简体中文", "繁體中文", "русский"). Case-insensitive
// for Latin letters. "enGB" is English. False (and `out` untouched) for anything else.
bool ParseLang(std::string_view word, Lang& out);

class Catalog
{
public:
    struct Entry
    {
        char const* en;
        char const* tr;
    };

    Catalog() = default;
    explicit Catalog(std::vector<Entry> const& entries) { for (Entry const& e : entries) Add(e.en, e.tr); }

    // False when the entry is malformed: an empty side, a template with two `{}` next to each other (no text between them to tell
    // the captures apart), a translation that uses a capture the template does not have, or a duplicate English text.
    bool Add(std::string_view en, std::string_view tr);

    // A line of the bots' stock chatter (the database texts of migration 0019) with its placeholders written the database's way:
    // `%name` (letters, digits, _) and `<name>` (lower-case letters). Each placeholder of `en` becomes a capture (`{}`, or `{#}` /
    // `{$}` / `{@}` / `{!}` for the ones BotTextMgr fills with a number / money / chat links / a name); each one in `tr` becomes the
    // capture of the same placeholder, so the translation may put them in any order. False (and refused, as Add) when `tr`
    // names a placeholder `en` has not got, either side has a `{` or `}` of its own, or there are more than 9.
    bool AddChatter(std::string_view en, std::string_view tr);

    // As Add, but an English text that is already in the catalog gets `tr` as one more translation instead of being refused (one
    // of a line's translations is picked at random each time it is sent). A second translation must be well formed on its own
    // and use only the captures the English text has.
    bool AddVariant(std::string_view en, std::string_view tr);
    // As AddChatter, with AddVariant's rule for an English line that is already in the catalog.
    bool AddChatterVariant(std::string_view en, std::string_view tr);

    // `text` in the catalog's language, or `text` unchanged when nothing matches.
    std::string Translate(std::string_view text) const;
    // `text` in the catalog's language into `out`; false (and `out` untouched) when nothing matches.
    bool TryTranslate(std::string_view text, std::string& out) const;

    // True when Translate would change `text` (for the coverage counter and the tests).
    bool Knows(std::string_view text) const;

    size_t Size() const { return exact_.size() + patterns_.size(); }
    // Every translation, the variants of a line counted one by one (Size counts each English line once).
    size_t Translations() const { return translations_; }

    // A captured amount of money ("1g 20s 5c", BotTrade::FormatMoney) is written with these units instead of g / s / c.
    void SetMoneyUnits(std::string gold, std::string silver, std::string copper)
    {
        money_[0] = std::move(gold); money_[1] = std::move(silver); money_[2] = std::move(copper);
    }

    // The entries Add refused, as "english" lines (shown by the unit test, so a typo in the table is caught before a build).
    std::vector<std::string> const& Rejected() const { return rejected_; }

private:
    struct Pattern
    {
        std::vector<std::string> lits;   // fixed texts around the captures: captures = lits.size() - 1
        std::vector<char>        kinds;  // per capture: 'a' any text, '?' any or none, '#' a number, '$' money, '@' a chat link, '!' one word
        std::vector<std::string> trs;    // one or more translations, one picked per use
        size_t                   fixed = 0;   // letters in lits, for the most-specific-first order
        size_t                   typed = 0;   // captures of a narrow kind (# $ @ !), the tie-break of that order
    };

    bool AddImpl(std::string_view en, std::string_view tr, bool variant);
    bool AddChatterImpl(std::string_view en, std::string_view tr, bool variant);
    bool TranslateInto(std::string_view text, std::string& out, int depth) const;
    bool TranslateList(std::string_view text, std::string& out, int depth) const;
    bool MatchPattern(Pattern const& p, std::string_view text, std::vector<std::string_view>& caps) const;
    std::string Fill(std::string_view tr, std::vector<std::string_view> const& caps, int depth) const;

    std::unordered_map<std::string, std::vector<std::string>> exact_;
    std::vector<Pattern>                                      patterns_;   // most fixed letters first
    std::vector<std::string>                                  rejected_;
    std::string                                               money_[3];   // empty: money stays as it is
    size_t                                                    translations_ = 0;
};

// Which of `n` translations a line gets: random (a thread-local generator). Tests make it repeatable with SeedVariantPick.
size_t PickVariant(size_t n);
void SeedVariantPick(uint32_t seed);

// The catalog of a language: its code lines, then its stock chatter (Util/BotLocale<Xx>.cpp). Built on first use, read-only
// afterwards. English has an empty catalog (it is the source text).
Catalog const& CatalogOf(Lang lang);
// The tables of a language: the code lines and the stock chatter lines (keyed on the database text, as RussianChatterEntries
// is). For every language but Russian the same English text may appear more than once: those are variants (AddVariant).
std::vector<Catalog::Entry> const& Entries(Lang lang);
std::vector<Catalog::Entry> const& ChatterEntries(Lang lang);

// The Russian catalog (Util/BotLocaleRu.cpp): the code's lines, then the stock chatter. Built on first use.
Catalog const& Russian();
std::vector<Catalog::Entry> const& RussianEntries();
// The bots' stock chatter in Russian (Util/BotLocaleRu.cpp), added to Russian() with Catalog::AddChatter: the English side is the
// database line of migration 0019 exactly as stored (playerbot_v2_bot_text.text).
std::vector<Catalog::Entry> const& RussianChatterEntries();

// The tables of the other languages (Util/BotLocaleDe.cpp, ...): same shape as the Russian ones.
std::vector<Catalog::Entry> const& GermanEntries();
std::vector<Catalog::Entry> const& GermanChatterEntries();
std::vector<Catalog::Entry> const& FrenchEntries();
std::vector<Catalog::Entry> const& FrenchChatterEntries();
std::vector<Catalog::Entry> const& SpanishEntries();         // esES
std::vector<Catalog::Entry> const& SpanishChatterEntries();
std::vector<Catalog::Entry> const& MexicanEntries();         // esMX: what is said otherwise in Latin America (esES fills the rest)
std::vector<Catalog::Entry> const& MexicanChatterEntries();
std::vector<Catalog::Entry> const& BrazilianEntries();       // ptBR
std::vector<Catalog::Entry> const& BrazilianChatterEntries();
std::vector<Catalog::Entry> const& KoreanEntries();
std::vector<Catalog::Entry> const& KoreanChatterEntries();
std::vector<Catalog::Entry> const& SimplifiedChineseEntries();
std::vector<Catalog::Entry> const& SimplifiedChineseChatterEntries();
std::vector<Catalog::Entry> const& TraditionalChineseEntries();
std::vector<Catalog::Entry> const& TraditionalChineseChatterEntries();

// `text` for a player reading `lang`: that language's catalog, then the sister catalog (esMX <-> esES), then English.
std::string Translate(Lang lang, std::string_view text);
// True when `lang` (or its sister catalog) would change `text`.
bool Knows(Lang lang, std::string_view text);

// Lines that must reach the client exactly as written whatever the reader's language: the add-on's structured whispers.
bool NeverTranslate(std::string_view text);

} // namespace Playerbot::Locale
