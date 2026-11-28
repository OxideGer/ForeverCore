// BotLocaleNamePicker - the name a new bot character gets from the language pools (Fleet/BotLocaleNames.h).
//
// Which pool: Playerbot.Localization.NameLocale
//   "default"  the server language (Playerbot.Localization.DefaultLocale; "auto" there = the realm's DBCLocale)
//   "players"  the client languages of the real players seen since the server started, each new bot drawing from one of
//              them at random, weighted by how many players read it (a mostly German realm gets mostly German names)
//   "off"      no language pool: the database name pools as before
//   enUS deDE esES esMX frFR ruRU koKR ptBR zhCN zhTW   that pool only (deDE: only German names)
//
// A name is taken only when it is free (no character has it), not reserved, and passes the core's ObjectMgr::CheckPlayerName for
// that locale (so the realm's StrictPlayerNames and the client data's profanity lists decide, never this list). When the
// chosen pool has no free name left for the bot's gender, Pick returns empty and the caller falls back to the database pools
// and the syllable generator, so bot creation never fails for a used-up list. Existing characters are never renamed.

#pragma once

#include "Define.h"
#include <string>

namespace Playerbot::V2::Fleet::LocaleNamePicker {

// A free name from the configured pool for a bot of `gender` (0 male, 1 female), or empty (pool off or used up).
std::string Pick(uint8 gender);

} // namespace Playerbot::V2::Fleet::LocaleNamePicker
