#include "BotLocaleNames.h"

namespace Playerbot::V2::Fleet::LocaleNames {

std::vector<Name> const& Pool(Locale::Lang lang)
{
    static std::vector<Name> const none;
    switch (lang)
    {
        case Locale::Lang::En:   return EnglishNames();
        case Locale::Lang::Ru:   return RussianNames();
        case Locale::Lang::De:   return GermanNames();
        case Locale::Lang::Fr:   return FrenchNames();
        case Locale::Lang::EsES: return SpanishNames();
        case Locale::Lang::EsMX: return MexicanNames();
        case Locale::Lang::PtBR: return BrazilianNames();
        case Locale::Lang::Ko:   return KoreanNames();
        case Locale::Lang::ZhCN: return SimplifiedChineseNames();
        case Locale::Lang::ZhTW: return TraditionalChineseNames();
        default:                 return none;
    }
}

namespace {

enum class Script { None, Latin, Cyrillic, Korean, Chinese };

// The ranges of the core (src/common/Utilities/Util.h: isExtendedLatinCharacter, isCyrillicCharacter, isKoreanCharacter,
// isChineseCharacter). Halfwidth forms, Bopomofo and the jamo are left out on purpose: a name is whole syllables or characters.
Script ScriptOf(char32_t c)
{
    if ((c >= U'a' && c <= U'z') || (c >= U'A' && c <= U'Z')) return Script::Latin;
    if ((c >= 0xC0 && c <= 0xD6) || (c >= 0xD8 && c <= 0xDE) || c == 0xDF || (c >= 0xE0 && c <= 0xF6) || (c >= 0xF8 && c <= 0xFE) ||
        (c >= 0x100 && c <= 0x12F) || c == 0x1E9E)
        return Script::Latin;
    if ((c >= 0x410 && c <= 0x44F) || c == 0x401 || c == 0x451) return Script::Cyrillic;
    if (c >= 0xAC00 && c <= 0xD7A3) return Script::Korean;
    if ((c >= 0x4E00 && c <= 0x9FFF) || (c >= 0x3400 && c <= 0x4DBF) || (c >= 0xF900 && c <= 0xFAFF)) return Script::Chinese;
    return Script::None;
}

bool IsUpper(char32_t c)
{
    if (c >= U'A' && c <= U'Z') return true;
    if ((c >= 0xC0 && c <= 0xD6) || (c >= 0xD8 && c <= 0xDE)) return true;
    if (c >= 0x100 && c <= 0x12F) return (c % 2) == 0;
    if (c >= 0x410 && c <= 0x42F) return true;
    return c == 0x401 || c == 0x1E9E;
}

char32_t Lower(char32_t c)
{
    if (c >= U'A' && c <= U'Z') return c + 32;
    if ((c >= 0xC0 && c <= 0xD6) || (c >= 0xD8 && c <= 0xDE)) return c + 0x20;
    if (c >= 0x100 && c <= 0x12F && c % 2 == 0) return c + 1;
    if (c >= 0x410 && c <= 0x42F) return c + 0x20;
    if (c == 0x401) return 0x451;
    if (c == 0x1E9E) return 0xDF;
    return c;
}

bool Decode(std::string_view s, std::vector<char32_t>& out)
{
    for (size_t i = 0; i < s.size();)
    {
        unsigned char const b = static_cast<unsigned char>(s[i]);
        size_t n;
        char32_t c;
        if (b < 0x80) { n = 1; c = b; }
        else if ((b >> 5) == 0x6) { n = 2; c = b & 0x1F; }
        else if ((b >> 4) == 0xE) { n = 3; c = b & 0x0F; }
        else if ((b >> 3) == 0x1E) { n = 4; c = b & 0x07; }
        else return false;
        if (i + n > s.size()) return false;
        for (size_t k = 1; k < n; ++k)
        {
            unsigned char const cb = static_cast<unsigned char>(s[i + k]);
            if ((cb >> 6) != 0x2) return false;
            c = (c << 6) | (cb & 0x3F);
        }
        out.push_back(c);
        i += n;
    }
    return true;
}

} // namespace

bool FitsCoreRules(std::string_view utf8, std::string* why)
{
    auto fail = [why](char const* reason) { if (why) *why = reason; return false; };
    std::vector<char32_t> cps;
    if (!Decode(utf8, cps)) return fail("not valid UTF-8");
    if (cps.size() < 2) return fail("shorter than 2 letters");
    if (cps.size() > 12) return fail("longer than 12 letters");
    Script const script = ScriptOf(cps[0]);
    if (script == Script::None) return fail("a sign the core does not allow in a name");
    for (char32_t c : cps)
    {
        Script const s = ScriptOf(c);
        if (s == Script::None) return fail("a sign the core does not allow in a name");
        if (s != script) return fail("letters of two scripts");
    }
    if (script == Script::Latin || script == Script::Cyrillic)
    {
        if (!IsUpper(cps[0])) return fail("first letter not upper case (the core stores it so)");
        for (size_t i = 1; i < cps.size(); ++i)
            if (IsUpper(cps[i])) return fail("an upper-case letter after the first (the core stores the rest lower case)");
    }
    for (size_t i = 2; i < cps.size(); ++i)
        if (Lower(cps[i]) == Lower(cps[i - 1]) && Lower(cps[i]) == Lower(cps[i - 2]))
            return fail("one letter three times in a row");
    return true;
}

} // namespace Playerbot::V2::Fleet::LocaleNames
