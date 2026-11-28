#include "BotLocaleNamePicker.h"

#include "BotLocaleNames.h"
#include "../Api/BotLanguage.h"
#include "CharacterCache.h"
#include "Config.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "Random.h"

#include <atomic>
#include <mutex>
#include <unordered_set>

namespace Playerbot::V2::Fleet::LocaleNamePicker {

namespace {

// Names handed out but maybe not in the character cache yet (the character is created after Roll returns), so two bots
// rolled in a row never get the same one. A name of a creation that failed stays blocked until the next start: harmless.
std::mutex                      g_handed_mtx;
std::unordered_set<std::string> g_handed;

std::atomic<uint32> g_exhausted_logged{ 0 };   // bit per language: "pool used up" logged once

enum class Mode { Off, Fixed, Players };

Mode ReadMode(Locale::Lang& fixed)
{
    std::string const v = sConfigMgr->GetStringDefault("Playerbot.Localization.NameLocale", "default", true);
    if (v == "off" || v == "OFF" || v == "0") return Mode::Off;
    if (v == "players" || v == "PLAYERS") return Mode::Players;
    if (v.empty() || v == "default" || v == "DEFAULT" || v == "auto" || v == "AUTO")
    {
        fixed = BotLanguage::ServerLang();
        return Mode::Fixed;
    }
    if (Locale::ParseLang(v, fixed)) return Mode::Fixed;
    static std::atomic<bool> warned{ false };
    if (!warned.exchange(true))
        TC_LOG_ERROR("playerbot.v2", "[names] Playerbot.Localization.NameLocale = \"{}\" is unknown; using the server language", v);
    fixed = BotLanguage::ServerLang();
    return Mode::Fixed;
}

// A language of the real players, weighted by how many read it; the server language when none logged in yet.
Locale::Lang PlayersLang()
{
    uint32 counts[Locale::kLangCount];
    BotLanguage::CountReaderLangs(counts);
    uint32 total = 0;
    for (uint32 n : counts) total += n;
    if (!total) return BotLanguage::ServerLang();
    uint32 roll = urand(0, total - 1);
    for (size_t i = 0; i < Locale::kLangCount; ++i)
    {
        if (roll < counts[i]) return Locale::Lang(i);
        roll -= counts[i];
    }
    return BotLanguage::ServerLang();
}

bool Usable(std::string const& name, Locale::Lang lang)
{
    if (sCharacterCache->GetCharacterCacheByName(name)) return false;
    if (sObjectMgr->IsReservedName(name)) return false;
    return ObjectMgr::CheckPlayerName(name, LocaleConstant(Locale::LocaleOf(lang)), true) == CHAR_NAME_SUCCESS;
}

std::string PickFrom(Locale::Lang lang, uint8 gender)
{
    std::vector<LocaleNames::Name> const& pool = LocaleNames::Pool(lang);
    if (pool.empty()) return {};
    // Start at a random place and walk the whole list once: every free name has the same chance, and a list with only a
    // few free names left still finds them.
    size_t const start = urand(0, uint32(pool.size() - 1));
    std::lock_guard lk(g_handed_mtx);
    for (size_t k = 0; k < pool.size(); ++k)
    {
        LocaleNames::Name const& n = pool[(start + k) % pool.size()];
        if (!LocaleNames::FitsGender(n.gender, gender)) continue;
        std::string name(n.text);
        if (g_handed.count(name) || !Usable(name, lang)) continue;
        g_handed.insert(name);
        return name;
    }
    uint32 const bit = 1u << uint32(lang);
    if (!(g_exhausted_logged.fetch_or(bit) & bit))
        TC_LOG_INFO("playerbot.v2", "[names] the {} name list has no free name left for gender {}; new bots take names from the "
            "database pools (add names in Fleet/Names/BotNames*.cpp)", Locale::LangCode(lang), gender);
    return {};
}

} // namespace

std::string Pick(uint8 gender)
{
    Locale::Lang lang = Locale::Lang::En;
    switch (ReadMode(lang))
    {
        case Mode::Off:     return {};
        case Mode::Players: return PickFrom(PlayersLang(), gender);
        case Mode::Fixed:   return PickFrom(lang, gender);
    }
    return {};
}

} // namespace Playerbot::V2::Fleet::LocaleNamePicker
