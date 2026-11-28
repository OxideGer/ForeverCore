/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

// The bots' languages beyond English and Russian (Util/BotLocaleText.h): locale mapping, the catalogs of every language, the
// fallback chain and the variants. The Russian behaviour itself is tested in ClassicBotLocale.cpp.

#include "tc_catch2.h"

#ifdef TESTS_HAVE_PLAYERBOT_V2

#include "../../src/modules/PlayerbotV2/Util/BotLocaleText.h"
#include "../../src/modules/PlayerbotV2/Bot/Quest/QuestRefusal.h"
#include <cctype>
#include <set>
#include <string>

using namespace Playerbot::Locale;

namespace
{
// The core's LocaleConstant numbers (src/common/Common.h), spelled out so a renumbering there shows up here.
constexpr uint8_t kEnUS = 0, kKoKR = 1, kFrFR = 2, kDeDE = 3, kZhCN = 4, kZhTW = 5, kEsES = 6, kEsMX = 7, kRuRU = 8, kNone = 9,
                  kPtBR = 10, kItIT = 11;

std::multiset<std::string> Captures(std::string const& en)
{
    std::multiset<std::string> out;
    for (size_t i = 0; i + 1 < en.size(); ++i)
        if (en[i] == '{' && en[i + 1] == '}') out.insert("{}");
        else if (en[i] == '{' && i + 2 < en.size() && en[i + 2] == '}' && std::string("?#$@!").find(en[i + 1]) != std::string::npos)
            out.insert("{}");
    return out;
}

int Slots(std::string const& tr)
{
    int n = 0;
    for (size_t i = 0; i + 1 < tr.size(); ++i)
        if (tr[i] == '{' && (tr[i + 1] == '}' || (tr[i + 1] >= '1' && tr[i + 1] <= '9')))
            ++n;
    return n;
}

std::multiset<std::string> ChatterPlaceholders(std::string const& s)
{
    std::multiset<std::string> out;
    for (size_t i = 0; i < s.size(); ++i)
    {
        size_t j = i + 1;
        if (s[i] == '%')
            while (j < s.size() && (std::isalnum(static_cast<unsigned char>(s[j])) || s[j] == '_')) ++j;
        else if (s[i] == '<')
        {
            while (j < s.size() && s[j] >= 'a' && s[j] <= 'z') ++j;
            if (j >= s.size() || s[j] != '>') continue;
            ++j;
        }
        else
            continue;
        if (j > i + 1)
            out.insert(s.substr(i, j - i));
    }
    return out;
}

// Valid UTF-8, no control characters but none at all (a catalog line is one chat line).
bool CleanUtf8(std::string const& s)
{
    for (size_t i = 0; i < s.size();)
    {
        unsigned char const c = static_cast<unsigned char>(s[i]);
        size_t n = c < 0x80 ? 1 : (c >> 5) == 0x6 ? 2 : (c >> 4) == 0xE ? 3 : (c >> 3) == 0x1E ? 4 : 0;
        if (!n || i + n > s.size()) return false;
        if (n == 1 && c < 0x20) return false;
        for (size_t k = 1; k < n; ++k)
            if ((static_cast<unsigned char>(s[i + k]) >> 6) != 0x2) return false;
        i += n;
    }
    return true;
}

Lang AllLangs(size_t i) { return Lang(i); }
}

TEST_CASE("BotLocaleLangs: every client locale maps to its language, the rest to English", "[BotLocale]")
{
    CHECK(LangFromLocale(kEnUS) == Lang::En);
    CHECK(LangFromLocale(kKoKR) == Lang::Ko);
    CHECK(LangFromLocale(kFrFR) == Lang::Fr);
    CHECK(LangFromLocale(kDeDE) == Lang::De);
    CHECK(LangFromLocale(kZhCN) == Lang::ZhCN);
    CHECK(LangFromLocale(kZhTW) == Lang::ZhTW);
    CHECK(LangFromLocale(kEsES) == Lang::EsES);
    CHECK(LangFromLocale(kEsMX) == Lang::EsMX);
    CHECK(LangFromLocale(kRuRU) == Lang::Ru);
    CHECK(LangFromLocale(kPtBR) == Lang::PtBR);
    // Not a WoW Forever bot language: English.
    CHECK(LangFromLocale(kItIT) == Lang::En);
    CHECK(LangFromLocale(kNone) == Lang::En);
    CHECK(LangFromLocale(200) == Lang::En);

    // The stable numbers the send points and the stored choice rely on.
    CHECK(uint8_t(Lang::En) == 0);
    CHECK(uint8_t(Lang::Ru) == 1);
    CHECK(kLangCount == 10);

    std::set<std::string> codes;
    for (size_t i = 0; i < kLangCount; ++i)
    {
        Lang const l = AllLangs(i);
        INFO(LangCode(l));
        CHECK(LangFromLocale(LocaleOf(l)) == l);
        CHECK(std::string(LangCode(l)).size() == 4);
        CHECK(*LangNativeName(l));
        CHECK(CleanUtf8(LangNativeName(l)));
        codes.insert(LangCode(l));
        Lang parsed = Lang::Count;
        CHECK(ParseLang(LangCode(l), parsed));
        CHECK(parsed == l);
    }
    CHECK(codes.size() == kLangCount);
}

TEST_CASE("BotLocaleLangs: language words", "[BotLocale]")
{
    auto parse = [](std::string_view w) { Lang l = Lang::Count; return ParseLang(w, l) ? l : Lang::Count; };
    CHECK(parse("en") == Lang::En);
    CHECK(parse("enGB") == Lang::En);
    CHECK(parse("en-GB") == Lang::En);
    CHECK(parse("ru") == Lang::Ru);
    CHECK(parse("Русский") == Lang::Ru);
    CHECK(parse("de") == Lang::De);
    CHECK(parse("Deutsch") == Lang::De);
    CHECK(parse("de_DE") == Lang::De);
    CHECK(parse("fr") == Lang::Fr);
    CHECK(parse("français") == Lang::Fr);
    CHECK(parse("es") == Lang::EsES);
    CHECK(parse("español") == Lang::EsES);
    CHECK(parse("mx") == Lang::EsMX);
    CHECK(parse("esMX") == Lang::EsMX);
    CHECK(parse("pt") == Lang::PtBR);
    CHECK(parse("ptBR") == Lang::PtBR);
    CHECK(parse("ko") == Lang::Ko);
    CHECK(parse("한국어") == Lang::Ko);
    CHECK(parse("cn") == Lang::ZhCN);
    CHECK(parse("简体中文") == Lang::ZhCN);
    CHECK(parse("tw") == Lang::ZhTW);
    CHECK(parse("繁體中文") == Lang::ZhTW);
    // Not a language: refused, the output left alone.
    CHECK(parse("itIT") == Lang::Count);
    CHECK(parse("klingon") == Lang::Count);
    CHECK(parse("") == Lang::Count);
}

TEST_CASE("BotLocaleLangs: every catalog is well formed", "[BotLocale]")
{
    for (size_t i = 1; i < kLangCount; ++i)
    {
        Lang const l = AllLangs(i);
        INFO(LangCode(l));
        Catalog const& c = CatalogOf(l);
        for (std::string const& bad : c.Rejected())
            FAIL_CHECK("refused: " << bad);
        CHECK(c.Rejected().empty());
        // Every entry is taken; a line that is in both tables with the same translation counts once.
        std::set<std::pair<std::string, std::string>> pairs;
        for (Catalog::Entry const& e : Entries(l)) pairs.emplace(e.en, e.tr);
        for (Catalog::Entry const& e : ChatterEntries(l)) pairs.emplace(e.en, e.tr);
        CHECK(c.Translations() == (l == Lang::Ru ? Entries(l).size() + ChatterEntries(l).size() : pairs.size()));

        for (Catalog::Entry const& e : Entries(l))
        {
            INFO(e.en);
            CHECK(*e.en);
            CHECK(*e.tr);
            CHECK(CleanUtf8(e.en));
            CHECK(CleanUtf8(e.tr));
            // A translation that drops a capture loses a name or a number the player needs.
            CHECK(Slots(e.tr) == int(Captures(e.en).size()));
        }
        for (Catalog::Entry const& e : ChatterEntries(l))
        {
            INFO(e.en);
            CHECK(*e.tr);
            CHECK(CleanUtf8(e.tr));
            // A variant may leave a placeholder out (a native line says it its own way), never use one the line has not got.
            std::multiset<std::string> const en = ChatterPlaceholders(e.en);
            for (std::string const& ph : ChatterPlaceholders(e.tr))
            {
                INFO(ph);
                CHECK(en.count(ph) > 0);
            }
        }
    }
}

TEST_CASE("BotLocaleLangs: English and unknown lines stay as they are in every language", "[BotLocale]")
{
    for (size_t i = 0; i < kLangCount; ++i)
    {
        Lang const l = AllLangs(i);
        INFO(LangCode(l));
        CHECK(Translate(l, "Perf: ticks=5 emit=3 zzq") == "Perf: ticks=5 emit=3 zzq");
        CHECK(Translate(l, "") == "");
        CHECK(Translate(l, "ASSIGN|END|3") == "ASSIGN|END|3");
    }
    CHECK(Translate(Lang::En, "Rento: following you") == "Rento: following you");
    CHECK(!Knows(Lang::En, "Rento: following you"));
    // Out of range: English, never a crash.
    CHECK(Translate(Lang::Count, "following you") == "following you");
}

TEST_CASE("BotLocaleLangs: Mexican Spanish falls back on the Spanish of Spain", "[BotLocale]")
{
    // Every line of the esES catalog reaches an esMX reader too: in Mexican wording where esMX has its own, else as esES writes it.
    for (Catalog::Entry const& e : SpanishEntries())
    {
        if (std::string(e.en).find('{') != std::string::npos) continue;
        INFO(e.en);
        CHECK(Knows(Lang::EsMX, e.en));
        CHECK(Translate(Lang::EsMX, e.en) != e.en);
    }
    for (Catalog::Entry const& e : MexicanEntries())
    {
        if (std::string(e.en).find('{') != std::string::npos) continue;
        INFO(e.en);
        CHECK(Knows(Lang::EsES, e.en));
    }
}

TEST_CASE("BotLocaleLangs: variants", "[BotLocale]")
{
    Catalog c;
    CHECK(c.AddVariant("boss down", "Der lag schneller als mein Feierabendbier."));
    CHECK(c.AddVariant("boss down", "Sauber!"));
    CHECK(c.AddVariant("boss down", "Na bitte, ging doch!"));
    CHECK(!c.AddVariant("boss down", "Sauber!"));        // the same line twice: a typo
    CHECK(!c.Add("boss down", "Noch einer"));            // Add keeps refusing a second translation
    CHECK(c.AddVariant("{} died", "{} testet den Boden"));
    CHECK(c.AddVariant("{} died", "RIP {}"));
    CHECK(!c.AddVariant("{} died", "{2} weg"));          // a capture the line has not got
    CHECK(c.Size() == 2);
    CHECK(c.Translations() == 5);
    CHECK(c.Rejected().size() == 3);

    std::set<std::string> seen, seen_tpl;
    SeedVariantPick(42);
    for (int i = 0; i < 200; ++i)
    {
        seen.insert(c.Translate("boss down"));
        seen_tpl.insert(c.Translate("Brok died"));
    }
    CHECK(seen == std::set<std::string>{ "Der lag schneller als mein Feierabendbier.", "Sauber!", "Na bitte, ging doch!" });
    CHECK(seen_tpl == std::set<std::string>{ "Brok testet den Boden", "RIP Brok" });

    // The same seed gives the same picks (tests and replays).
    SeedVariantPick(7);
    std::string const a = c.Translate("boss down") + c.Translate("boss down") + c.Translate("boss down");
    SeedVariantPick(7);
    std::string const b = c.Translate("boss down") + c.Translate("boss down") + c.Translate("boss down");
    CHECK(a == b);

    // Chatter variants: the placeholders of the database line, in any order, any subset.
    Catalog chat;
    CHECK(chat.AddChatterVariant("hi %s", "Moin %s!"));
    CHECK(chat.AddChatterVariant("hi %s", "Na, alles fit?"));
    CHECK(!chat.AddChatterVariant("hi %s", "Hallo %t"));  // not a placeholder of the line
    std::set<std::string> hi;
    for (int i = 0; i < 100; ++i) hi.insert(chat.Translate("hi Karrz"));
    CHECK(hi == std::set<std::string>{ "Moin Karrz!", "Na, alles fit?" });
}

TEST_CASE("BotLocaleLangs: money in each client's own letters", "[BotLocale]")
{
    Catalog c;
    c.SetMoneyUnits("g", "s", "k");
    CHECK(c.Add("costs {$}", "kostet {}"));
    CHECK(c.Translate("costs 1g 20s 5c") == "kostet 1g 20s 5k");
}

TEST_CASE("BotLocaleLangs: German replies", "[BotLocale]")
{
    // Code lines: captures, nested words (class, spec, role), "Name: rest", money letters.
    CHECK(Translate(Lang::De, "Rento: following you") == "Rento: folgt dir");
    CHECK(Translate(Lang::De, "Zelah: attacking Kobold Miner") == "Zelah: greife Kobold Miner an");
    CHECK(Translate(Lang::De, "Rento: level 20 Mage (Fire), dps - following you") == "Rento: Level 20 Magier (Feuer), DD – folgt dir");
    CHECK(Translate(Lang::De, "i'll give you 35s 2c for that") == "dafür geb ich dir 35s 2k");
    CHECK(Translate(Lang::De, "Pull back: pulling Hogger to the rally point.") == "Pull zurück: ziehe Hogger zum Sammelpunkt.");
    CHECK(Translate(Lang::De, "Tactics for Baron Geddon: boss first.") == "Taktik für Baron Geddon: erst der Boss.");
    CHECK(Translate(Lang::De, "that was Brok's fault") == "das war Broks Schuld");
    CHECK(Translate(Lang::De, "Prefer: Blessing of Might, pet off.") == "Vorzug: Segen der Macht, Pet aus.");
    // Player command words stay as the player types them.
    CHECK(Translate(Lang::De, "Raveni holds here and pulls nothing until you say 'go'.").find("'go'") != std::string::npos);

    // Every quest refusal has its German line, with the quest in it.
    for (uint8_t r = uint8_t(Playerbot::QuestRefusal::Other); r <= uint8_t(Playerbot::QuestRefusal::Unfinishable); ++r)
    {
        std::string const s = Playerbot::QuestRefusalLine(Playerbot::QuestRefusal(r), "Wolves");
        INFO(s);
        CHECK(Knows(Lang::De, s));
        CHECK(Translate(Lang::De, s).find("Wolves") != std::string::npos);
    }

    // Stock chatter: the German variants of a database line, placeholders filled.
    std::set<std::string> hello;
    for (int i = 0; i < 200; ++i) hello.insert(Translate(Lang::De, "hi Karrz"));
    CHECK(hello == std::set<std::string>{ "Hi Karrz", "Moin Karrz" });
    std::set<std::string> loot;
    for (int i = 0; i < 200; ++i) loot.insert(Translate(Lang::De, "OMG, look at what I just got |cffa335ee|Hitem:19019|h[Thunderfury]|h|r!!!"));
    CHECK(loot.size() == 2);
    for (std::string const& l : loot) CHECK(l.find("[Thunderfury]") != std::string::npos);

    // German readers get no English line for the situations the bots talk about most.
    for (char const* en : { "Hello", "Goodbye!", "OOM", "Heal me!", "ready", "gg", "my bad", "wipe :(", "Ding!" })
    {
        INFO(en);
        CHECK(Knows(Lang::De, en));
    }
}

#endif
