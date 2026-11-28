// Spanish bot names of Spain (esES): the nicks Spanish players pick. Spanish gamer slang (manco, paquete, máquina, crack),
// the "cuñado" and "yayo" humour, tapas and bar culture, Chiquito-style catchphrases, Golden Age literature and fables.
// The Latin American pool is its own list (Fleet/Names/BotNamesEsMX.cpp). Stored form: first letter upper case, rest lower
// case, at most 12 letters.

#include "../BotLocaleNames.h"

namespace Playerbot::V2::Fleet::LocaleNames {

std::vector<Name> const& SpanishNames()
{
    static std::vector<Name> const names = {
        // ---- gamer slang ----------------------------------------------------------------------------------------------------
        { "Paquete", kAny }, { "Paquetón", kMale }, { "Manco", kMale }, { "Manca", kFemale }, { "Mancazo", kMale },
        { "Nubazo", kMale }, { "Máquina", kAny }, { "Fiera", kFemale }, { "Crack", kAny }, { "Crackete", kMale },
        { "Figura", kAny }, { "Leyenda", kFemale }, { "Bestia", kAny }, { "Fenómeno", kMale }, { "Tremendo", kMale },
        { "Puntazo", kAny }, { "Golazo", kAny }, { "Chetado", kMale }, { "Chetada", kFemale }, { "Rusheador", kMale },
        { "Campero", kMale }, { "Farmeador", kMale }, { "Lagazo", kAny }, { "Afkero", kMale }, { "Ragequit", kAny },
        { "Tryhardeo", kAny }, { "Noobeo", kAny }, { "Pulleador", kMale }, { "Wipeador", kMale }, { "Lootero", kMale },
        { "Robaloot", kAny }, { "Ninjeador", kMale }, { "Dadosmalos", kAny }, { "Necesidad", kAny }, { "Codicia", kAny },
        { "Tanquecito", kMale }, { "Tanquazo", kMale }, { "Sanadora", kFemale }, { "Curandero", kMale }, { "Curandera", kFemale },
        { "Matasanos", kAny }, { "Tirita", kFemale }, { "Brujilla", kFemale }, { "Brujo", kMale }, { "Magazo", kMale },
        { "Hechicera", kFemale }, { "Chamanazo", kMale }, { "Druidilla", kFemale }, { "Paladino", kMale }, { "Pícaro", kMale },
        { "Pícara", kFemale }, { "Cazador", kMale }, { "Cazadora", kFemale }, { "Guerrero", kMale }, { "Guerrera", kFemale },
        { "Sacerdotisa", kFemale }, { "Monaguillo", kMale }, { "Cura", kMale }, { "Curita", kAny }, { "Enanito", kMale },
        { "Gnomito", kAny }, { "Gnomazo", kMale }, { "Elfito", kMale }, { "Elfa", kFemale }, { "Orquito", kMale },
        { "Trolazo", kMale }, { "Vacalola", kFemale }, { "Zombi", kAny }, { "Calavera", kFemale }, { "Huesitos", kAny },
        { "Ovejita", kFemale }, { "Bolafuego", kAny }, { "Escarcha", kAny }, { "Rayito", kAny }, { "Truenazo", kAny },
        { "Puñalada", kAny }, { "Navajero", kMale }, { "Sombrita", kAny }, { "Flechazo", kAny }, { "Ballestero", kMale },
        // ---- everyday slang of Spain ---------------------------------------------------------------------------------
        { "Tronco", kMale }, { "Chaval", kMale }, { "Chavala", kFemale }, { "Colega", kAny }, { "Mola", kAny },
        { "Molamazo", kAny }, { "Guay", kAny }, { "Flipao", kMale }, { "Flipada", kFemale }, { "Pringao", kMale },
        { "Cuñao", kMale }, { "Cuñadísimo", kMale }, { "Cuñada", kFemale }, { "Abuelete", kMale }, { "Yayo", kMale },
        { "Yaya", kFemale }, { "Yayoflauta", kAny }, { "Pijo", kMale }, { "Pija", kFemale }, { "Chulo", kMale },
        { "Chulapo", kMale }, { "Chulapa", kFemale }, { "Majete", kMale }, { "Majeta", kFemale }, { "Gañán", kMale },
        { "Zasca", kAny }, { "Tomaya", kAny }, { "Andaya", kAny }, { "Yavoy", kAny }, { "Enseguida", kAny },
        { "Ahoravuelvo", kAny }, { "Unmomentito", kAny }, { "Vuelvoya", kAny }, { "Quétepasa", kAny }, { "Quéfuerte", kAny },
        { "Nopasanada", kAny }, { "Ojitoaldato", kAny }, { "Atope", kAny }, { "Mazo", kAny }, { "Petarlo", kAny },
        { "Liarla", kAny }, { "Lamadre", kAny }, { "Madremía", kAny }, { "Virgencita", kFemale }, { "Ayomá", kAny },
        { "Fistro", kAny }, { "Pecador", kMale }, { "Pecadora", kFemale }, { "Cobarde", kAny }, { "Torpedo", kAny },
        { "Gromenaguer", kAny }, { "Siesta", kAny }, { "Siestero", kMale }, { "Mañana", kAny }, { "Mañanero", kMale },
        { "Olé", kAny }, { "Flamenco", kAny }, { "Castañuela", kFemale }, { "Verbena", kFemale }, { "Romería", kFemale },
        { "Despistao", kMale }, { "Despistada", kFemale }, { "Tardón", kMale }, { "Tardona", kFemale }, { "Vago", kMale },
        { "Vaga", kFemale }, { "Gruñón", kMale }, { "Gruñona", kFemale }, { "Cotilla", kAny }, { "Chismoso", kMale },
        { "Sabelotodo", kAny }, { "Listillo", kMale }, { "Listilla", kFemale }, { "Pillo", kMale }, { "Pilla", kFemale },
        { "Granuja", kAny }, { "Bribón", kMale }, { "Bribona", kFemale }, { "Truhán", kMale }, { "Golfillo", kMale },
        // ---- food, drink and bar ----------------------------------------------------------------------------------------
        { "Paella", kAny }, { "Tortilla", kAny }, { "Jamonero", kMale }, { "Croqueta", kFemale }, { "Croquetón", kMale },
        { "Patatabrava", kAny }, { "Gazpacho", kAny }, { "Salmorejo", kAny }, { "Calimocho", kAny }, { "Sangría", kFemale },
        { "Cañita", kFemale }, { "Tapeo", kAny }, { "Tapitas", kAny }, { "Churrero", kMale }, { "Porra", kAny },
        { "Chorizo", kAny }, { "Morcilla", kFemale }, { "Fabada", kFemale }, { "Cocido", kAny }, { "Chupito", kAny },
        { "Botellón", kAny }, { "Resaca", kFemale }, { "Bocata", kAny }, { "Bocadillo", kAny }, { "Pincho", kAny },
        { "Boquerón", kAny }, { "Calamares", kAny }, { "Pulpito", kAny }, { "Pulpoalagall", kAny }, { "Torrezno", kAny },
        { "Ensaimada", kFemale }, { "Turrón", kAny }, { "Polvorón", kAny }, { "Mazapán", kAny }, { "Rosquilla", kFemale },
        { "Horchata", kFemale }, { "Cafetito", kAny }, { "Carajillo", kAny }, { "Tintoverano", kAny }, { "Vermú", kAny },
        { "Aceituna", kFemale }, { "Pimiento", kAny }, { "Migas", kAny }, { "Fartón", kAny }, { "Sobrasada", kFemale },
        // ---- literature, fables and legends ----------------------------------------------------------------------------
        { "Quijote", kMale }, { "Sanchopanza", kMale }, { "Dulcinea", kFemale }, { "Rocinante", kAny }, { "Lazarillo", kMale },
        { "Celestina", kFemale }, { "Elcid", kMale }, { "Tizona", kAny }, { "Donjuan", kMale }, { "Bernardo", kMale },
        { "Hidalgo", kMale }, { "Caballero", kMale }, { "Escudero", kMale }, { "Juglar", kMale }, { "Trovador", kMale },
        { "Ratónpérez", kMale }, { "Cocoloco", kAny }, { "Coco", kMale }, { "Meiga", kFemale }, { "Trasgu", kAny },
        { "Cuélebre", kAny }, { "Xana", kFemale }, { "Ojancano", kMale }, { "Santacompaña", kAny }, { "Duende", kAny },
        { "Molinero", kMale }, { "Pastorcillo", kMale }, { "Gigantón", kMale }, { "Cabezudo", kMale }, { "Fallero", kMale },
        { "Fallera", kFemale }, { "Ninot", kAny }, { "Petardo", kAny }, { "Mascletá", kAny }, { "Tamborrada", kAny },
    };
    return names;
}

} // namespace Playerbot::V2::Fleet::LocaleNames
