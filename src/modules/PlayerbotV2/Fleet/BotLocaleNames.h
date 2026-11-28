// BotLocaleNames - the bots' character names per client language (pure: no game objects, unit tested).
//
// Each WoW Forever client language has its own pool of names in the style its players pick: German pun names for a German realm,
// Russian gamer names for a Russian one, Hangul names for Korean, Hanzi for the Chinese realms. They are original names written
// for that community, not translations of one list. Every entry already has the form the core stores (first letter upper case,
// the rest lower case: "Haudruff", not "HauDruff") and passes the core's rules (FitsCoreRules below, and the unit test).
//
// A character name is global: a bot has one name for every reader, so the pool is chosen server-wide
// (Playerbot.Localization.NameLocale, Fleet/BotLocaleNamePicker.cpp), never per reader. Existing characters keep their names.
//
// The lists live in Fleet/Names/BotNames<Xx>.cpp. English has its own list of player-style names; the database pools
// (Fleet/BotNamePool) and the syllable generator stay as the fallback when a list is used up.

#pragma once

#include "../Util/BotLocaleText.h"

#include <cstdint>
#include <string>
#include <string_view>
#include <vector>

namespace Playerbot::V2::Fleet::LocaleNames {

// The look a name fits: a male name, a female one, or either. Matched against the bot's gender (0 male, 1 female).
enum : uint8_t { kMale = 0, kFemale = 1, kAny = 2 };

struct Name
{
    char const* text;     // UTF-8, as the core stores it
    uint8_t     gender;   // kMale, kFemale or kAny
};

// The pool of a language (empty for an unknown one).
std::vector<Name> const& Pool(Locale::Lang lang);

// The pools one by one (Fleet/Names/BotNames<Xx>.cpp).
std::vector<Name> const& EnglishNames();
std::vector<Name> const& RussianNames();
std::vector<Name> const& GermanNames();
std::vector<Name> const& FrenchNames();
std::vector<Name> const& SpanishNames();
std::vector<Name> const& MexicanNames();
std::vector<Name> const& BrazilianNames();
std::vector<Name> const& KoreanNames();
std::vector<Name> const& SimplifiedChineseNames();
std::vector<Name> const& TraditionalChineseNames();

// True when a name of this gender may go to a bot of `bot_gender` (0 male, 1 female).
inline bool FitsGender(uint8_t name_gender, uint8_t bot_gender) { return name_gender == kAny || name_gender == bot_gender; }

// The core's own name rules, written out without the core (ObjectMgr::CheckPlayerName and normalizePlayerName with
// StrictPlayerNames = 0): 2 to 12 letters; letters of one script only (extended Latin as the core counts it, Cyrillic, Hangul
// or CJK); no digits, blanks or signs; no letter three times in a row; and already in the stored form (Latin and Cyrillic:
// first letter upper case, the rest lower case). False with the reason in `why`. The live check at use still runs the core's
// CheckPlayerName (profanity and reserved lists of the client data, the realm's StrictPlayerNames) before a name is taken.
bool FitsCoreRules(std::string_view utf8, std::string* why = nullptr);

} // namespace Playerbot::V2::Fleet::LocaleNames
