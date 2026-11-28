// German bot names (deDE): what German players call their characters. Puns on food and drink, dialect, fairy tales and
// children's books, Ruhrpott / Bavarian / North German flavour, and WoW slang as German players use it ("Aggro", "Heal",
// "Tank" are loanwords here). Stored form: first letter upper case, rest lower case, at most 12 letters (Fleet/BotLocaleNames.h).

#include "../BotLocaleNames.h"

namespace Playerbot::V2::Fleet::LocaleNames {

std::vector<Name> const& GermanNames()
{
    static std::vector<Name> const names = {
        // ---- WoW and gamer slang, German style -------------------------------------------------------------------------
        { "Kritikus", kAny }, { "Haudruff", kAny }, { "Heilbutt", kAny }, { "Manamangel", kAny }, { "Aggromagnet", kAny },
        { "Lootgeier", kAny }, { "Gnomnomnom", kAny }, { "Feierabend", kAny }, { "Tankstelle", kAny }, { "Tankwart", kMale },
        { "Wipeprofi", kAny }, { "Wipemeister", kMale }, { "Pullmeister", kMale }, { "Zuvielpull", kAny }, { "Repkosten", kAny },
        { "Goldfarmer", kAny }, { "Mobtreiber", kMale }, { "Heilmichel", kMale }, { "Heilnudel", kFemale }, { "Heilfee", kFemale },
        { "Manatrinker", kAny }, { "Manaschluck", kAny }, { "Manamaus", kFemale }, { "Afkbert", kMale }, { "Lagkönig", kMale },
        { "Bedarfheini", kMale }, { "Gierschlund", kAny }, { "Würfelglück", kAny }, { "Würfelpech", kAny }, { "Lootfee", kFemale },
        { "Epixjäger", kMale }, { "Grünzeugs", kAny }, { "Graumüll", kAny }, { "Taschenvoll", kAny }, { "Rucksacktier", kAny },
        { "Wunderheiler", kMale }, { "Quacksalber", kMale }, { "Wundpflaster", kAny }, { "Sonntagsheal", kAny },
        { "Kampfkuschel", kAny }, { "Draufhauer", kMale }, { "Hauruck", kAny }, { "Kloppmann", kMale }, { "Raufbold", kMale },
        { "Prügelknabe", kMale }, { "Haudegen", kMale }, { "Schildbürger", kAny }, { "Schwertheini", kMale }, { "Schreihals", kAny },
        { "Rumpelstilz", kMale }, { "Bierfürst", kMale }, { "Latrinenlord", kMale },
        // ---- classes and races, with a wink -----------------------------------------------------------------------------
        { "Frostbeule", kAny }, { "Eiszapfen", kAny }, { "Feuerteufel", kAny }, { "Flammkuchen", kAny }, { "Zauberazubi", kAny },
        { "Hexenschuss", kAny }, { "Hexenbesen", kFemale }, { "Kräuterhexe", kFemale }, { "Wasserkocher", kAny },
        { "Brotkorb", kAny }, { "Portalonkel", kMale }, { "Schafmacher", kAny }, { "Schäfchen", kFemale }, { "Mäh", kAny },
        { "Schleichbub", kMale }, { "Messerjocke", kMale }, { "Hinterhältig", kAny }, { "Taschendieb", kMale },
        { "Schattenmann", kMale }, { "Totenkopf", kAny }, { "Knochenkalle", kMale }, { "Gruftie", kAny }, { "Zombiekalle", kMale },
        { "Lichtgestalt", kAny }, { "Gebetsmühle", kAny }, { "Kreuzritter", kMale }, { "Weihwasser", kAny }, { "Blubbhelm", kAny },
        { "Beichtvater", kMale }, { "Seelsorger", kMale }, { "Pfaffe", kMale }, { "Höllenhund", kAny }, { "Teufelskerl", kMale },
        { "Seelenklau", kAny }, { "Dämonenoma", kFemale }, { "Pfeilgift", kAny }, { "Bogenhansi", kMale }, { "Jägerlatein", kAny },
        { "Waidmann", kMale }, { "Tierfreund", kAny }, { "Miezekatze", kFemale }, { "Wauwau", kAny }, { "Fiffi", kAny },
        { "Totemtante", kFemale }, { "Totemtoni", kMale }, { "Regentanz", kAny }, { "Donnerwetter", kAny }, { "Blitzbirne", kAny },
        { "Wetterfrosch", kAny }, { "Baumkuschler", kAny }, { "Eichhörnchen", kAny }, { "Bärchen", kAny }, { "Teddybär", kAny },
        { "Waldschrat", kMale }, { "Moosbart", kMale }, { "Pilzkopf", kAny }, { "Pilzsammler", kMale }, { "Muhkuh", kFemale },
        { "Kuhfladen", kAny }, { "Zwergenwut", kAny }, { "Zwergnase", kAny }, { "Bartpfleger", kMale }, { "Bartgott", kMale },
        { "Spitzohr", kAny }, { "Langohr", kAny }, { "Wichtel", kAny }, { "Gartenzwerg", kAny }, { "Schrumpfgnom", kAny },
        { "Omagnom", kFemale }, { "Grünhaut", kAny }, { "Orkan", kAny }, { "Trollololo", kAny }, { "Trolli", kAny },
        // ---- food and drink ----------------------------------------------------------------------------------------------
        { "Wurstwasser", kAny }, { "Brezelbaron", kMale }, { "Sauerkraut", kAny }, { "Schnitzelboy", kMale },
        { "Dönerprinz", kMale }, { "Spätzlespatz", kAny }, { "Currywurst", kAny }, { "Currykönig", kMale }, { "Grillmeister", kMale },
        { "Kaffeekanne", kAny }, { "Kaffeejunkie", kAny }, { "Weißwurst", kAny }, { "Leberkäs", kAny }, { "Obatzda", kAny },
        { "Bierbauch", kMale }, { "Biergarten", kAny }, { "Radler", kAny }, { "Kölschkönig", kMale }, { "Prost", kAny },
        { "Zapfhahn", kAny }, { "Apfelschorle", kAny }, { "Spezi", kAny }, { "Mettigel", kAny }, { "Mettbrötchen", kAny },
        { "Fischkopp", kAny }, { "Labskaus", kAny }, { "Rollmops", kAny }, { "Sauerbraten", kAny }, { "Semmelknödel", kAny },
        { "Kässpätzle", kAny }, { "Maultasche", kAny }, { "Bienenstich", kAny }, { "Lebkuchen", kAny }, { "Glühwein", kAny },
        { "Pfeffernuss", kAny }, { "Pommesbude", kAny }, { "Pommesgabel", kAny }, { "Kartoffel", kAny }, { "Pustekuchen", kAny },
        { "Gurkenglas", kAny }, { "Senftube", kAny }, { "Knäckebrot", kAny }, { "Schwarzwald", kAny }, { "Rumtopf", kAny },
        // ---- sayings, dialect and everyday German ------------------------------------------------------------------------
        { "Ottonormal", kAny }, { "Keinplan", kAny }, { "Nullplan", kAny }, { "Mahlzeit", kAny }, { "Stammtisch", kAny },
        { "Schlafmütze", kAny }, { "Pennbruder", kMale }, { "Sofaheld", kMale }, { "Sofaheldin", kFemale }, { "Ehrenmann", kMale },
        { "Ehrenfrau", kFemale }, { "Lauch", kAny }, { "Lauchkrieger", kMale }, { "Alman", kAny }, { "Almanpower", kAny },
        { "Alterschwede", kAny }, { "Holladiefee", kAny }, { "Waldfee", kFemale }, { "Läuftbeidir", kAny }, { "Gönndir", kAny },
        { "Spaßbremse", kAny }, { "Miesepeter", kMale }, { "Meckerliese", kFemale }, { "Besserwisser", kAny },
        { "Erbsenzähler", kAny }, { "Nörgelbert", kMale }, { "Grummelbär", kMale }, { "Brummbär", kMale }, { "Sauertopf", kAny },
        { "Glückspilz", kAny }, { "Pechvogel", kAny }, { "Tollpatsch", kAny }, { "Schussel", kAny }, { "Hansdampf", kMale },
        { "Moinmoin", kAny }, { "Moin", kAny }, { "Servus", kAny }, { "Grüßgott", kAny }, { "Tachchen", kAny },
        { "Kneipentour", kAny }, { "Malocher", kMale }, { "Kumpel", kAny }, { "Ruhrpottkind", kAny }, { "Schnauze", kAny },
        { "Kiezkönig", kMale }, { "Hallodri", kMale }, { "Schlawiner", kMale }, { "Lausbub", kMale }, { "Bengel", kMale },
        { "Rotzlöffel", kAny }, { "Frechdachs", kAny }, { "Schlingel", kAny }, { "Racker", kAny }, { "Halunke", kMale },
        { "Strolch", kMale }, { "Taugenichts", kMale }, { "Sparfuchs", kAny }, { "Wutbürger", kAny }, { "Zackbumm", kAny },
        { "Kawumm", kAny }, { "Rumms", kAny }, { "Schepper", kAny }, { "Bratpfanne", kAny }, { "Dickbrocken", kAny },
        { "Kleingeld", kAny }, { "Dreikäsehoch", kAny }, { "Hasenfuß", kAny }, { "Angsthase", kAny }, { "Heulsuse", kFemale },
        { "Plappermaul", kAny }, { "Quasselkopp", kAny }, { "Naseweis", kAny }, { "Ohrwurm", kAny }, { "Kuddelmuddel", kAny },
        { "Tohuwabohu", kAny }, { "Larifari", kAny }, { "Firlefanz", kAny }, { "Papperlapapp", kAny }, { "Rambazamba", kAny },
        // ---- fairy tales, children's books, folk figures -----------------------------------------------------------------
        { "Suppenkaspar", kMale }, { "Kasperle", kMale }, { "Rotkäppchen", kFemale }, { "Rapunzel", kFemale },
        { "Dornröschen", kFemale }, { "Frauholle", kFemale }, { "Rübezahl", kMale }, { "Maxundmoritz", kAny },
        { "Witwebolte", kFemale }, { "Lehrerlämpel", kMale }, { "Hotzenplotz", kMale }, { "Sandmännchen", kMale },
        { "Urmel", kAny }, { "Strubbelkopf", kAny }, { "Eulenspiegel", kMale }, { "Lügenbaron", kMale }, { "Schneeweiß", kFemale },
        { "Hänsel", kMale }, { "Gretel", kFemale }, { "Froschkönig", kMale }, { "Däumling", kAny }, { "Gestiefelt", kAny }, { "Bremermusik", kAny },
    };
    return names;
}

} // namespace Playerbot::V2::Fleet::LocaleNames
