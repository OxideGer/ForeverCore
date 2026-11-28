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

// The bots' name lists per client language (Fleet/BotLocaleNames.h): every name must be one the core accepts and stores as
// written, every language has its own list, and nothing repeats inside a list.

#include "tc_catch2.h"

#ifdef TESTS_HAVE_PLAYERBOT_V2

#include "../../src/modules/PlayerbotV2/Fleet/BotLocaleNames.h"
#include <set>
#include <string>

using namespace Playerbot::V2::Fleet::LocaleNames;
namespace Loc = Playerbot::Locale;

namespace
{
std::string Lower(std::string s)
{
    // ASCII only: enough to catch "Name" / "name" twice in a Latin list (the core folds case before comparing names).
    for (char& c : s)
        if (c >= 'A' && c <= 'Z') c = char(c - 'A' + 'a');
    return s;
}
}

TEST_CASE("BotLocaleNames: the core's name rules", "[BotLocale]")
{
    std::string why;
    CHECK(FitsCoreRules("Haudruff"));
    CHECK(FitsCoreRules("Bierfürst"));
    CHECK(FitsCoreRules("Weißwurst"));
    CHECK(FitsCoreRules("Ölprinz"));
    CHECK(FitsCoreRules("Пивозавр"));
    CHECK(FitsCoreRules("Ёжик"));
    CHECK(FitsCoreRules("치느님"));
    CHECK(FitsCoreRules("摸鱼达人"));
    CHECK(FitsCoreRules("傻眼貓咪"));
    CHECK(FitsCoreRules("Gnomnomnom"));                       // no letter three times in a row
    CHECK(FitsCoreRules("Abcdefghijkl"));                     // 12 letters

    CHECK(!FitsCoreRules("HauDruff", &why));                  // the core stores "Haudruff"
    CHECK(!why.empty());
    CHECK(!FitsCoreRules("haudruff"));
    CHECK(!FitsCoreRules("Abcdefghijklm"));                   // 13 letters
    CHECK(!FitsCoreRules("A"));
    CHECK(!FitsCoreRules("Leet1337"));
    CHECK(!FitsCoreRules("Hau Druff"));
    CHECK(!FitsCoreRules("Hau'druff"));
    CHECK(!FitsCoreRules("Hau-druff"));
    CHECK(!FitsCoreRules("Bääär"));                           // three ä
    CHECK(!FitsCoreRules("Booob"));
    CHECK(!FitsCoreRules("Pewпиу"));                          // two scripts
    CHECK(!FitsCoreRules("阿Q"));
    CHECK(!FitsCoreRules("ㅋㅋ"));                             // jamo, not syllables
    CHECK(!FitsCoreRules("Łukasz"));                          // outside the core's Latin range
    CHECK(!FitsCoreRules(std::string("\xC3\x28", 2)));        // broken UTF-8
}

TEST_CASE("BotLocaleNames: every language has its own list of valid names", "[BotLocale]")
{
    std::set<std::string> first_names;
    for (size_t i = 0; i < Loc::kLangCount; ++i)
    {
        Loc::Lang const lang = Loc::Lang(i);
        INFO(Loc::LangCode(lang));
        std::vector<Name> const& pool = Pool(lang);
        CHECK(pool.size() >= 200);

        std::set<std::string> seen;
        size_t male = 0, female = 0;
        for (Name const& n : pool)
        {
            INFO(n.text);
            std::string why;
            CHECK(FitsCoreRules(n.text, &why));
            if (!why.empty()) FAIL_CHECK(why);
            CHECK(n.gender <= kAny);
            CHECK(seen.insert(Lower(n.text)).second);          // not twice in one list
            if (FitsGender(n.gender, 0)) ++male;
            if (FitsGender(n.gender, 1)) ++female;
        }
        // Both genders find plenty of names.
        CHECK(male >= 150);
        CHECK(female >= 150);
        // The lists are their own, not one list copied: their first entries differ.
        CHECK(first_names.insert(pool.front().text).second);
    }
}

TEST_CASE("BotLocaleNames: the lists are in their language's script", "[BotLocale]")
{
    auto first_byte = [](char const* s) { return static_cast<unsigned char>(s[0]); };
    for (Name const& n : Pool(Loc::Lang::Ru))
    {
        INFO(n.text);
        CHECK((first_byte(n.text) == 0xD0 || first_byte(n.text) == 0xD1));   // Cyrillic
    }
    for (Loc::Lang lang : { Loc::Lang::Ko, Loc::Lang::ZhCN, Loc::Lang::ZhTW })
        for (Name const& n : Pool(lang))
        {
            INFO(n.text);
            CHECK(first_byte(n.text) >= 0xE0);                                  // Hangul / Hanzi: three-byte UTF-8
        }
    for (Loc::Lang lang : { Loc::Lang::En, Loc::Lang::De, Loc::Lang::Fr, Loc::Lang::EsES, Loc::Lang::EsMX, Loc::Lang::PtBR })
        for (Name const& n : Pool(lang))
        {
            INFO(n.text);
            CHECK(first_byte(n.text) < 0xD0);                                   // Latin
        }
    CHECK(Pool(Loc::Lang::Count).empty());
}

TEST_CASE("BotLocaleNames: gender fit", "[BotLocale]")
{
    CHECK(FitsGender(kAny, 0));
    CHECK(FitsGender(kAny, 1));
    CHECK(FitsGender(kMale, 0));
    CHECK(!FitsGender(kMale, 1));
    CHECK(FitsGender(kFemale, 1));
    CHECK(!FitsGender(kFemale, 0));
}

#endif
