// Latin American Spanish bot names (esMX): the nicks of Mexican and Latin American players, not the Spanish of Spain.
// Mexican slang (chido, carnal, morro, órale, nel pastel, simón limón), street food and taquería culture, regional
// nicknames (chilango, regio, tapatío, jarocho), lucha libre, Día de Muertos and folklore (La Llorona, chupacabras,
// alebrije, ajolote). Stored form: first letter upper case, rest lower case, at most 12 letters.

#include "../BotLocaleNames.h"

namespace Playerbot::V2::Fleet::LocaleNames {

std::vector<Name> const& MexicanNames()
{
    static std::vector<Name> const names = {
        // ---- Mexican slang ---------------------------------------------------------------------------------------------
        { "Chido", kAny }, { "Chidísimo", kMale }, { "Güey", kMale }, { "Carnal", kMale }, { "Carnalito", kMale },
        { "Compa", kAny }, { "Compadre", kMale }, { "Comadre", kFemale }, { "Cuate", kMale }, { "Cuatacho", kMale },
        { "Chavo", kMale }, { "Chava", kFemale }, { "Morro", kMale }, { "Morra", kFemale }, { "Chamaco", kMale },
        { "Chamaca", kFemale }, { "Escuincle", kAny }, { "Fresa", kAny }, { "Fresita", kFemale }, { "Gacho", kMale },
        { "Padrísimo", kMale }, { "Neta", kAny }, { "Netita", kAny }, { "Simón", kMale }, { "Órale", kAny },
        { "Ándale", kAny }, { "Híjole", kAny }, { "Ajúa", kAny }, { "Chale", kAny }, { "Nelpastel", kAny },
        { "Simónlimón", kAny }, { "Aguas", kAny }, { "Fierro", kAny }, { "Pariente", kAny }, { "Quiubo", kAny },
        { "Quéonda", kAny }, { "Ahítevidrio", kAny }, { "Alratito", kAny }, { "Ahorita", kAny }, { "Ahoritita", kAny },
        { "Achis", kAny }, { "Ay", kAny }, { "Ayaycaray", kAny }, { "Nombre", kAny }, { "Chaparrito", kMale },
        { "Chafa", kAny }, { "Chafita", kAny }, { "Pirata", kAny }, { "Bien", kAny }, { "Bienperro", kAny },
        { "Padrino", kMale }, { "Aventado", kMale }, { "Aventada", kFemale }, { "Mamalón", kMale }, { "Machín", kMale },
        { "Güerito", kMale }, { "Güerita", kFemale }, { "Chaparrita", kFemale }, { "Fodongo", kMale }, { "Fodonga", kFemale },
        { "Mitotero", kMale }, { "Mitotera", kFemale }, { "Chismosa", kFemale }, { "Metiche", kAny }, { "Codo", kMale },
        { "Coda", kFemale }, { "Gorrón", kMale }, { "Gorrona", kFemale }, { "Chillón", kMale }, { "Chillona", kFemale },
        // ---- gamers -----------------------------------------------------------------------------------------------------
        { "Bienmanco", kAny }, { "Mancote", kMale }, { "Noobsote", kMale }, { "Tryharder", kAny }, { "Jalador", kMale },
        { "Farmerito", kMale }, { "Lootcito", kAny }, { "Rateado", kMale }, { "Lagueado", kMale }, { "Teclazo", kAny },
        { "Clickeador", kMale }, { "Carreado", kMale }, { "Carrito", kAny }, { "Chofer", kMale }, { "Chafatank", kAny },
        { "Tanquezote", kMale }, { "Curanderito", kMale }, { "Yerbera", kFemale }, { "Hierbero", kMale }, { "Sobador", kMale },
        { "Huesero", kMale }, { "Bruja", kFemale }, { "Brujote", kMale }, { "Nahual", kAny }, { "Chamánzote", kMale },
        { "Magote", kMale }, { "Hechicerito", kMale }, { "Rateroso", kMale }, { "Ratero", kMale }, { "Ratera", kFemale },
        { "Arquero", kMale }, { "Arquera", kFemale }, { "Machetero", kMale }, { "Machetazo", kAny }, { "Chanclazo", kAny },
        { "Chancla", kFemale }, { "Lachancla", kFemale }, { "Cinturonazo", kAny }, { "Resortera", kFemale }, { "Trompo", kAny },
        { "Balero", kAny }, { "Canica", kFemale }, { "Lotería", kFemale }, { "Eldiablito", kMale }, { "Lacatrina", kFemale },
        // ---- food and drink -------------------------------------------------------------------------------------------
        { "Taquero", kMale }, { "Taquera", kFemale }, { "Taquito", kAny }, { "Alpastor", kAny }, { "Quesadilla", kAny },
        { "Gordita", kFemale }, { "Chilaquil", kAny }, { "Tamalero", kMale }, { "Tamalito", kAny }, { "Elotero", kMale },
        { "Elote", kAny }, { "Esquite", kAny }, { "Pozole", kAny }, { "Molepoblano", kAny }, { "Tortaahogada", kAny },
        { "Guacamole", kAny }, { "Mezcalito", kAny }, { "Tequilero", kMale }, { "Pulquero", kMale }, { "Michelada", kFemale },
        { "Chelero", kMale }, { "Chela", kFemale }, { "Unachela", kAny }, { "Cheve", kAny }, { "Horchatita", kFemale },
        { "Jamaica", kFemale }, { "Tepache", kAny }, { "Atolito", kAny }, { "Champurrado", kAny }, { "Conchita", kFemale },
        { "Panmuerto", kAny }, { "Chicharrón", kAny }, { "Carnitas", kAny }, { "Barbacoa", kAny }, { "Birria", kFemale },
        { "Sope", kAny }, { "Huarache", kAny }, { "Tlayuda", kFemale }, { "Gorditas", kAny }, { "Tostada", kFemale },
        { "Totopo", kAny }, { "Salsaverde", kAny }, { "Habanero", kMale }, { "Chipotle", kAny }, { "Jalapeño", kMale },
        { "Chilito", kAny }, { "Picosito", kAny }, { "Limoncito", kAny }, { "Tamarindo", kAny }, { "Mangochile", kAny },
        // ---- regions, lucha libre and fiesta ------------------------------------------------------------------------
        { "Chilango", kMale }, { "Chilanga", kFemale }, { "Regio", kMale }, { "Regia", kFemale }, { "Tapatío", kMale },
        { "Tapatía", kFemale }, { "Jarocho", kMale }, { "Jarocha", kFemale }, { "Norteño", kMale }, { "Norteña", kFemale },
        { "Yucateco", kMale }, { "Oaxaqueña", kFemale }, { "Poblano", kMale }, { "Sinaloense", kAny }, { "Sonorense", kAny },
        { "Mariachi", kAny }, { "Charro", kMale }, { "Charra", kFemale }, { "Ranchero", kMale }, { "Ranchera", kFemale },
        { "Luchador", kMale }, { "Luchadora", kFemale }, { "Enmascarado", kMale }, { "Rudo", kMale }, { "Técnico", kMale },
        { "Máscara", kAny }, { "Llave", kAny }, { "Plancha", kAny }, { "Quebradora", kAny }, { "Hurracarrana", kAny },
        { "Piñata", kFemale }, { "Posada", kFemale }, { "Pastorela", kFemale }, { "Quinceañera", kFemale }, { "Serenata", kFemale },
        { "Zapateado", kAny }, { "Huapango", kAny }, { "Cumbiero", kMale }, { "Sonidero", kMale }, { "Corrido", kAny },
        // ---- folklore and nature ----------------------------------------------------------------------------------
        { "Llorona", kFemale }, { "Chupacabras", kAny }, { "Alebrije", kAny }, { "Calaca", kFemale }, { "Calaverita", kAny },
        { "Catrina", kFemale }, { "Cempasúchil", kAny }, { "Xolo", kAny }, { "Ajolote", kAny }, { "Ajolotito", kAny },
        { "Quetzal", kAny }, { "Colibrí", kAny }, { "Tlacuache", kAny }, { "Mapache", kAny }, { "Coyote", kAny },
        { "Chapulín", kAny }, { "Nopal", kAny }, { "Nopalito", kAny }, { "Maguey", kAny }, { "Cacomixtle", kAny },
        { "Charal", kAny }, { "Pinole", kAny }, { "Duendecito", kAny }, { "Aluxe", kAny }, { "Chaneque", kAny },
    };
    return names;
}

} // namespace Playerbot::V2::Fleet::LocaleNames
