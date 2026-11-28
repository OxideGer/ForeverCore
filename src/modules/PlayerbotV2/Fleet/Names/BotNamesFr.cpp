// French bot names (frFR): the pseudos French-speaking players choose. Puns on races and classes (Paladingue, Nainternet,
// Gnomade, Orquestre), French internet slang (Kikoolol, Ptdr, Jeanmichel), cheese and cuisine, sayings, and the classics
// of French literature and legend. Stored form: first letter upper case, rest lower case, at most 12 letters.

#include "../BotLocaleNames.h"

namespace Playerbot::V2::Fleet::LocaleNames {

std::vector<Name> const& FrenchNames()
{
    static std::vector<Name> const names = {
        // ---- puns on classes and races -----------------------------------------------------------------------------------
        { "Paladingue", kAny }, { "Nainvisible", kAny }, { "Nainternet", kAny }, { "Naindien", kAny }, { "Nainporte", kAny },
        { "Gnomade", kAny }, { "Gnomignon", kAny }, { "Elfabète", kAny }, { "Orchidée", kFemale }, { "Orquestre", kAny },
        { "Trollinette", kFemale }, { "Meuhmeuh", kAny }, { "Mortderire", kAny }, { "Mortelle", kFemale }, { "Zombiette", kFemale },
        { "Tankinou", kAny }, { "Soigneur", kMale }, { "Soigneuse", kFemale }, { "Magicien", kMale }, { "Sorcière", kFemale },
        { "Envoûteuse", kFemale }, { "Démoniste", kAny }, { "Chamanou", kAny }, { "Druidesse", kFemale }, { "Prêtresse", kFemale },
        { "Voleuse", kFemale }, { "Chasseuse", kFemale }, { "Guerrier", kMale }, { "Guerrière", kFemale }, { "Rebouteux", kMale },
        { "Guérisseuse", kFemale }, { "Toubib", kMale }, { "Charlatan", kMale }, { "Pansement", kAny }, { "Infirmière", kFemale },
        { "Bourrin", kMale }, { "Bourrine", kFemale }, { "Fonceur", kMale }, { "Fonceuse", kFemale }, { "Kamikaze", kAny },
        { "Chefderaid", kMale }, { "Cheffe", kFemale }, { "Dépouilleur", kMale }, { "Pillard", kMale }, { "Radin", kMale },
        { "Radine", kFemale }, { "Grippesou", kMale }, { "Fauché", kMale }, { "Fauchée", kFemale }, { "Pasdethune", kAny },
        { "Tropdemobs", kAny }, { "Encoreunpull", kAny }, { "Pasdepanique", kAny }, { "Àlattaque", kAny }, { "Onyva", kAny },
        { "Allezgo", kAny }, { "Jetank", kAny }, { "Jesoigne", kAny }, { "Soignemoi", kAny }, { "Plusdemana", kAny },
        { "Lagueur", kMale }, { "Afkeur", kMale }, { "Lootophile", kAny }, { "Mobophobe", kAny }, { "Wipeur", kMale },
        { "Repoptoi", kAny }, { "Moutonneur", kMale }, { "Moutonne", kFemale }, { "Bêlement", kAny }, { "Pouletmagic", kAny },
        { "Fléchette", kAny }, { "Arbalète", kAny }, { "Gourdin", kAny }, { "Bouclier", kAny }, { "Grimoire", kAny },
        { "Baguettor", kMale }, { "Bâtonmagique", kAny }, { "Chaudron", kAny }, { "Potionmagic", kAny }, { "Elixir", kAny },
        // ---- internet slang and everyday expressions -------------------------------------------------------------------
        { "Kikoolol", kAny }, { "Jeanmichel", kMale }, { "Jeankevin", kMale }, { "Jeanmimi", kMale }, { "Ohlala", kAny },
        { "Sacrebleu", kAny }, { "Morbleu", kAny }, { "Parbleu", kAny }, { "Saperlotte", kAny }, { "Zut", kAny },
        { "Zutalors", kAny }, { "Oupsi", kAny }, { "Tranquilou", kAny }, { "Kiffeur", kMale }, { "Kiffeuse", kFemale },
        { "Bogoss", kMale }, { "Malaise", kAny }, { "Gênant", kAny }, { "Wesh", kAny }, { "Ouaisouais", kAny },
        { "Ahbon", kAny }, { "Bahoui", kAny }, { "Ouiouioui", kAny }, { "Ptdr", kAny }, { "Mdr", kAny },
        { "Jpp", kAny }, { "Tavu", kAny }, { "Cébon", kAny }, { "Cétaitpasmoi", kAny }, { "Pasmoi", kAny },
        { "Jesuislà", kAny }, { "Jarrive", kAny }, { "Deuxsecondes", kAny }, { "Pausepipi", kAny }, { "Pausecafé", kAny },
        { "Jaifaim", kAny }, { "Cestpasfaux", kAny }, { "Ohmondieu", kAny }, { "Tkt", kAny }, { "Askip", kAny },
        { "Frérot", kMale }, { "Frangine", kFemale }, { "Pote", kAny }, { "Copain", kMale }, { "Copine", kFemale },
        { "Ladaronne", kFemale }, { "Tonton", kMale }, { "Tata", kFemale }, { "Mamie", kFemale }, { "Papy", kMale },
        { "Pépé", kMale }, { "Mémé", kFemale }, { "Pétanque", kAny }, { "Cochonnet", kAny }, { "Apéro", kAny },
        { "Apérobobo", kAny }, { "Bisou", kAny }, { "Bisous", kAny }, { "Câlin", kAny }, { "Doudou", kAny },
        { "Loulou", kAny }, { "Toutou", kAny }, { "Minou", kAny }, { "Nounours", kAny }, { "Chouchou", kAny },
        { "Chouquette", kFemale }, { "Poireau", kAny }, { "Navet", kAny }, { "Patate", kAny }, { "Frite", kAny },
        { "Râleur", kMale }, { "Râleuse", kFemale }, { "Grognon", kAny }, { "Ronchon", kAny }, { "Bougon", kAny },
        { "Flemmard", kMale }, { "Flemmarde", kFemale }, { "Glandeur", kMale }, { "Tirauflanc", kAny }, { "Rigolo", kMale },
        { "Rigolote", kFemale }, { "Farceur", kMale }, { "Coquin", kMale }, { "Coquine", kFemale }, { "Filou", kMale },
        { "Fripouille", kAny }, { "Canaille", kAny }, { "Chenapan", kMale }, { "Garnement", kMale }, { "Vaurien", kMale },
        // ---- food and drink --------------------------------------------------------------------------------------------
        { "Jambonbeurre", kAny }, { "Chocolatine", kAny }, { "Painauchoco", kAny }, { "Raclette", kAny }, { "Tartiflette", kAny },
        { "Fondue", kAny }, { "Camembert", kAny }, { "Roquefort", kAny }, { "Saucisson", kAny }, { "Cassoulet", kAny },
        { "Crêpe", kAny }, { "Galette", kAny }, { "Croquemadame", kFemale }, { "Pastis", kAny }, { "Pinard", kAny },
        { "Vinrouge", kAny }, { "Boulanger", kMale }, { "Boulangère", kFemale }, { "Fromager", kMale }, { "Quiche", kAny },
        { "Escargot", kAny }, { "Grenouille", kAny }, { "Moulefrite", kAny }, { "Choucroute", kAny }, { "Madeleine", kFemale },
        { "Macaron", kAny }, { "Clafoutis", kAny }, { "Profiterole", kAny }, { "Éclair", kAny }, { "Tartetatin", kAny },
        { "Ratatouille", kAny }, { "Painperdu", kAny }, { "Pastèque", kAny }, { "Brioche", kAny }, { "Baguette", kAny },
        { "Calvados", kAny }, { "Cidre", kAny }, { "Mirabelle", kFemale }, { "Pruneau", kAny }, { "Cornichon", kAny },
        { "Gratin", kAny }, { "Bouillon", kAny }, { "Potaufeu", kAny }, { "Pistou", kAny }, { "Aïoli", kAny },
        // ---- literature, legend and history ------------------------------------------------------------------------------
        { "Arsènelupin", kMale }, { "Cyrano", kMale }, { "Dartagnan", kMale }, { "Porthos", kMale }, { "Aramis", kMale },
        { "Athos", kMale }, { "Mousquetaire", kMale }, { "Quasimodo", kMale }, { "Esmeralda", kFemale }, { "Gavroche", kMale },
        { "Cosette", kFemale }, { "Javert", kMale }, { "Candide", kAny }, { "Perceval", kMale }, { "Karadoc", kMale },
        { "Gargantua", kMale }, { "Pantagruel", kMale }, { "Tartuffe", kMale }, { "Harpagon", kMale }, { "Bovary", kFemale },
        { "Lagrenouille", kAny }, { "Lerenard", kMale }, { "Goupil", kMale }, { "Ysengrin", kMale }, { "Barbebleue", kMale },
        { "Cendrillon", kFemale }, { "Peaudâne", kFemale }, { "Petitpoucet", kAny }, { "Mélusine", kFemale }, { "Merlin", kMale },
        { "Lancelot", kMale }, { "Gauvain", kMale }, { "Viviane", kFemale }, { "Morgane", kFemale }, { "Roland", kMale },
        { "Durandal", kAny }, { "Charlemagne", kMale }, { "Gaulois", kMale }, { "Gauloise", kFemale }, { "Tintamarre", kAny },
    };
    return names;
}

} // namespace Playerbot::V2::Fleet::LocaleNames
