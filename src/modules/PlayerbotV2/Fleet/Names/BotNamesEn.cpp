// English bot names (enUS): the usernames English-speaking players pick. Gamer memes and MMO slang, puns on classes and
// races, food, and the "joined words" style of an English realm. Stored form: first letter upper case, rest lower case, at
// most 12 letters (Fleet/BotLocaleNames.h). The database pool of real first names stays behind this list as the fallback.

#include "../BotLocaleNames.h"

namespace Playerbot::V2::Fleet::LocaleNames {

std::vector<Name> const& EnglishNames()
{
    static std::vector<Name> const names = {
        // ---- MMO slang and gamer memes ------------------------------------------------------------------------------------
        { "Pewpew", kAny }, { "Pewpewpew", kAny }, { "Facerollin", kAny }, { "Keyboardturn", kAny }, { "Clickerdude", kMale },
        { "Backpedals", kAny }, { "Tankandspank", kAny }, { "Healsforgold", kAny }, { "Needsmoredps", kAny }, { "Notmyfault", kAny },
        { "Itwaslag", kAny }, { "Lagmonster", kAny }, { "Afkautorun", kAny }, { "Autorunner", kAny }, { "Brbpizza", kAny },
        { "Snackattack", kAny }, { "Lootgoblin", kAny }, { "Ninjalooter", kAny }, { "Rolledneed", kAny }, { "Greedisgood", kAny },
        { "Onemorepull", kAny }, { "Pullmoar", kAny }, { "Moarpylons", kAny }, { "Gitgud", kAny }, { "Gitgudscrub", kAny },
        { "Nerfplz", kAny }, { "Buffplz", kAny }, { "Imonfire", kAny }, { "Standinfire", kAny }, { "Getoutofit", kAny },
        { "Corpserunner", kAny }, { "Repairbill", kAny }, { "Brokegear", kAny }, { "Pocketheals", kAny }, { "Pocketlint", kAny },
        { "Leeroy", kMale }, { "Noobmaster", kAny }, { "Noobsauce", kAny }, { "Pwnage", kAny }, { "Lolwut", kAny },
        { "Roflcopter", kAny }, { "Leetspeak", kAny }, { "Elitehaxor", kAny }, { "Tryhard", kAny }, { "Sweatlord", kMale },
        { "Casualdad", kMale }, { "Dadgamer", kMale }, { "Momgamer", kFemale }, { "Grandmaheals", kFemale }, { "Nanaheals", kFemale },
        { "Xxslayerxx", kAny }, { "Wipeagain", kAny }, { "Wipeclub", kAny }, { "Runback", kAny }, { "Ressplz", kAny },
        { "Waitformana", kAny }, { "Drinkingrn", kAny }, { "Oom", kAny }, { "Oomagain", kAny }, { "Manabreak", kAny },
        { "Dpsmeter", kAny }, { "Toprdps", kAny }, { "Parsegray", kAny }, { "Pumper", kAny }, { "Bigpumper", kMale },
        { "Carryme", kAny }, { "Busdriver", kAny }, { "Freerun", kAny }, { "Hardcarry", kAny }, { "Softcarry", kAny },
        { "Bisorbust", kAny }, { "Rngesus", kAny }, { "Rngblessed", kAny }, { "Rngcursed", kAny }, { "Dropratez", kAny },
        { "Cheesestrat", kAny }, { "Skipthetrash", kAny }, { "Trashpanda", kAny }, { "Patpull", kAny }, { "Bodypull", kAny },
        { "Aggroboy", kMale }, { "Aggrogirl", kFemale }, { "Threatcap", kAny }, { "Tauntbot", kAny }, { "Kitingking", kMale },
        // ---- classes and races ---------------------------------------------------------------------------------------------
        { "Sirstabsalot", kMale }, { "Stabbyjoe", kMale }, { "Stabbity", kAny }, { "Sneakypete", kMale }, { "Vanishbob", kMale },
        { "Shadowmeld", kAny }, { "Dotsonly", kAny }, { "Dotmaster", kAny }, { "Fearbomb", kAny }, { "Fearmonger", kAny },
        { "Sheepish", kAny }, { "Baabaa", kAny }, { "Sheepdip", kAny }, { "Chillpill", kAny }, { "Brainfreeze", kAny },
        { "Snowcone", kAny }, { "Waterboy", kMale }, { "Breadwinner", kAny }, { "Portalpls", kAny }, { "Blinkblink", kAny },
        { "Totemtom", kMale }, { "Totallytotem", kAny }, { "Windfurry", kAny }, { "Shockjock", kMale }, { "Thunderthigh", kAny },
        { "Cowabunga", kAny }, { "Holycow", kAny }, { "Steakhouse", kAny }, { "Mooveit", kAny }, { "Udderchaos", kAny },
        { "Hoofhearted", kAny }, { "Bearlyalive", kAny }, { "Pawsitive", kAny }, { "Furreal", kAny }, { "Treehugger", kAny },
        { "Leafmealone", kAny }, { "Boomkin", kAny }, { "Hotdots", kAny }, { "Bubblehearth", kAny }, { "Bubbleboi", kMale },
        { "Holysmokes", kAny }, { "Hammertime", kAny }, { "Prayforme", kAny }, { "Wandspec", kAny }, { "Petdeadagain", kAny },
        { "Petsitter", kAny }, { "Feigndeath", kAny }, { "Zugzug", kAny }, { "Loktarogar", kAny }, { "Throwinshade", kAny },
        { "Grumpydwarf", kMale }, { "Beardedfury", kMale }, { "Beerbelly", kMale }, { "Alehouse", kAny }, { "Tipsytroll", kAny },
        { "Gnomebody", kAny }, { "Gnomeless", kAny }, { "Gnometoss", kAny }, { "Shortstack", kAny }, { "Pocketgnome", kAny },
        { "Kneecapper", kAny }, { "Anklebiter", kAny }, { "Pointyears", kAny }, { "Undeadfred", kMale }, { "Notdeadyet", kAny },
        { "Boneapetit", kAny }, { "Skelebro", kMale }, { "Spooky", kAny }, { "Brainz", kAny }, { "Greenskin", kAny },
        { "Smashmouth", kAny }, { "Bigaxe", kAny }, { "Shieldwall", kAny }, { "Rageface", kAny }, { "Angrybob", kMale },
        { "Bandaidbob", kMale }, { "Flashheal", kAny }, { "Renewyou", kAny }, { "Holynova", kAny }, { "Smitey", kAny },
        { "Lockandload", kAny }, { "Soulshard", kAny }, { "Lifetapper", kAny }, { "Impkeeper", kAny }, { "Demonbro", kMale },
        { "Arrowtime", kAny }, { "Autoshot", kAny }, { "Scattershot", kAny }, { "Petbuster", kAny }, { "Bowdacious", kAny },
        // ---- food, drink and snacks --------------------------------------------------------------------------------------
        { "Cupcakes", kAny }, { "Pancakes", kAny }, { "Waffles", kAny }, { "Baconstrip", kAny }, { "Nachoaverage", kAny },
        { "Tacotuesday", kAny }, { "Coffeeheals", kAny }, { "Decafdruid", kAny }, { "Pizzaroll", kAny }, { "Hotsauce", kAny },
        { "Chickennugs", kAny }, { "Mozzastick", kAny }, { "Buttertoast", kAny }, { "Pickleback", kAny }, { "Grilledchez", kAny },
        { "Mapleleaf", kAny }, { "Poutine", kAny }, { "Fishnchips", kAny }, { "Bangers", kAny }, { "Teaandbiccy", kAny },
        { "Meatpie", kAny }, { "Fairybread", kAny }, { "Snagsizzle", kAny }, { "Bbqdad", kMale }, { "Brisket", kAny },
        { "Gravytrain", kAny }, { "Biscuits", kAny }, { "Cornbread", kAny }, { "Sweettea", kAny }, { "Mountainman", kMale },
        // ---- archetypes and everyday names ---------------------------------------------------------------------------------
        { "Stevethetank", kMale }, { "Garythemage", kMale }, { "Kevinofdoom", kMale }, { "Chadwarrior", kMale }, { "Davemcdave", kMale },
        { "Uncletank", kMale }, { "Auntiehealz", kFemale }, { "Grandpajoe", kMale }, { "Grannysmith", kFemale }, { "Sirbeardsley", kMale },
        { "Ladybeef", kFemale }, { "Missmolotov", kFemale }, { "Queenbee", kFemale }, { "Mrfluffles", kMale }, { "Mrsnuggles", kMale },
        { "Captainobv", kMale }, { "Bigbossman", kMale }, { "Lilbit", kAny }, { "Tinytim", kMale }, { "Bigjim", kMale },
        { "Couchpotato", kAny }, { "Sundayfunday", kAny }, { "Nightowl", kAny }, { "Earlybird", kAny }, { "Lastcall", kAny },
        { "Oneshot", kAny }, { "Twoshoes", kAny }, { "Lucky", kAny }, { "Jinxed", kAny }, { "Whoopsie", kAny },
        { "Mybad", kAny }, { "Notsorry", kAny }, { "Yolo", kAny }, { "Fomo", kAny }, { "Nope", kAny },
        { "Bigoof", kAny }, { "Welp", kAny }, { "Yeet", kAny }, { "Bruh", kAny }, { "Noscope", kAny },
        { "Kekw", kAny }, { "Poggers", kAny }, { "Ezclap", kAny }, { "Ggwp", kAny }, { "Glhf", kAny },
    };
    return names;
}

} // namespace Playerbot::V2::Fleet::LocaleNames
