// Brazilian Portuguese bot names (ptBR): the nicks of Brazilian players, not European Portuguese. Brazilian internet
// slang and memes (sextou, bora Bill, eita preula, mitou, tio do pavê), regional words (oxente, uai, bah, tchê, égua),
// food and boteco culture, and the folklore of the Sítio and the forest (Saci, Curupira, Iara, Boitatá).
// Stored form: first letter upper case, rest lower case, at most 12 letters.

#include "../BotLocaleNames.h"

namespace Playerbot::V2::Fleet::LocaleNames {

std::vector<Name> const& BrazilianNames()
{
    static std::vector<Name> const names = {
        // ---- internet slang and memes ----------------------------------------------------------------------------------
        { "Sextou", kAny }, { "Partiu", kAny }, { "Bora", kAny }, { "Borabill", kAny }, { "Eita", kAny },
        { "Eitapreula", kAny }, { "Mitou", kAny }, { "Mito", kMale }, { "Lenda", kFemale }, { "Tiodopavê", kMale },
        { "Pavê", kAny }, { "Tiozão", kMale }, { "Topzera", kAny }, { "Firmeza", kAny }, { "Suave", kAny },
        { "Tranquilão", kMale }, { "Deboa", kAny }, { "Daora", kAny }, { "Irado", kMale }, { "Irada", kFemale },
        { "Sinistro", kMale }, { "Sinistra", kFemale }, { "Brabo", kMale }, { "Braba", kFemale }, { "Monstro", kMale },
        { "Noobinho", kMale }, { "Noobzão", kMale }, { "Carregador", kMale }, { "Carreguei", kAny }, { "Peguei", kAny },
        { "Kakaka", kAny }, { "Rsrs", kAny }, { "Ksksks", kAny }, { "Aff", kAny }, { "Affs", kAny },
        { "Oloco", kAny }, { "Olokinho", kAny }, { "Caraca", kAny }, { "Cruzcredo", kAny }, { "Credo", kAny },
        { "Valeu", kAny }, { "Falou", kAny }, { "Fechou", kAny }, { "Tamojunto", kAny }, { "Demorou", kAny },
        { "Jáé", kAny }, { "Nãoémeu", kAny }, { "Foimal", kAny }, { "Foiolag", kAny }, { "Caiunet", kAny },
        { "Pingalto", kAny }, { "Lagado", kMale }, { "Afkzinho", kAny }, { "Voltojá", kAny }, { "Péraí", kAny },
        { "Calmaí", kAny }, { "Segura", kAny }, { "Vemmonstro", kAny }, { "Pulamais", kAny }, { "Puxamais", kAny },
        { "Wipeou", kAny }, { "Morri", kAny }, { "Morridenovo", kAny }, { "Revivepfv", kAny }, { "Curapfv", kAny },
        // ---- regional words and everyday nicknames --------------------------------------------------------------------
        { "Mano", kMale }, { "Parça", kAny }, { "Véi", kAny }, { "Cara", kAny }, { "Mina", kFemale },
        { "Gato", kMale }, { "Gata", kFemale }, { "Gatinha", kFemale }, { "Oxente", kAny }, { "Vixe", kAny },
        { "Uai", kAny }, { "Bah", kAny }, { "Tchê", kAny }, { "Barbaridade", kAny }, { "Égua", kAny },
        { "Arretado", kMale }, { "Arretada", kFemale }, { "Nordestino", kMale }, { "Gaúcho", kMale }, { "Gaúcha", kFemale },
        { "Carioca", kAny }, { "Paulista", kAny }, { "Mineirinho", kMale }, { "Mineirinha", kFemale }, { "Baiano", kMale },
        { "Baiana", kFemale }, { "Capixaba", kAny }, { "Manauara", kAny }, { "Potiguar", kAny }, { "Candango", kMale },
        { "Malandro", kMale }, { "Malandra", kFemale }, { "Zezinho", kMale }, { "Vovó", kFemale }, { "Vozinha", kFemale },
        { "Bisa", kFemale }, { "Madrinha", kFemale }, { "Padrinho", kMale }, { "Cumpadi", kMale }, { "Cumadi", kFemale },
        { "Pirralho", kMale }, { "Moleque", kMale }, { "Molecada", kAny }, { "Fofoqueira", kFemale }, { "Folgado", kMale },
        { "Folgada", kFemale }, { "Preguiçoso", kMale }, { "Preguiçosa", kFemale }, { "Esperto", kMale }, { "Espertinha", kFemale },
        { "Sortudo", kMale }, { "Sortuda", kFemale }, { "Azarado", kMale }, { "Azarada", kFemale }, { "Trapalhão", kMale },
        { "Atrapalhada", kFemale }, { "Pãoduro", kMale }, { "Muquirana", kAny }, { "Fominha", kAny }, { "Chorão", kMale },
        // ---- classes and races ------------------------------------------------------------------------------------------
        { "Tankudo", kMale }, { "Tankzinho", kMale }, { "Curandeira", kFemale }, { "Benzedeira", kFemale }, { "Rezadeira", kFemale },
        { "Pajé", kMale }, { "Xamã", kAny }, { "Bruxinha", kFemale }, { "Bruxão", kMale }, { "Feiticeira", kFemale },
        { "Magão", kMale }, { "Maguinha", kFemale }, { "Ladrãozinho", kMale }, { "Caçador", kMale }, { "Caçadora", kFemale },
        { "Guerreiro", kMale }, { "Guerreira", kFemale }, { "Paladinão", kMale }, { "Sacerdote", kMale }, { "Druidão", kMale },
        { "Anão", kMale }, { "Anãozinho", kMale }, { "Gnominho", kAny }, { "Elfinho", kMale }, { "Elfinha", kFemale },
        { "Orcão", kMale }, { "Trollzinho", kMale }, { "Taurão", kMale }, { "Vaquinha", kFemale }, { "Zumbi", kAny },
        { "Caveirinha", kFemale }, { "Ossinho", kAny }, { "Ursão", kMale }, { "Ursinho", kAny }, { "Corujinha", kFemale },
        { "Ovelhinha", kFemale }, { "Fogaréu", kAny }, { "Geladinho", kAny }, { "Raiozinho", kAny }, { "Trovão", kAny },
        { "Facada", kAny }, { "Sombrinha", kAny }, { "Flechada", kAny }, { "Estilingue", kAny }, { "Porrete", kAny },
        // ---- food and drink -------------------------------------------------------------------------------------------
        { "Pãodequeijo", kAny }, { "Coxinha", kFemale }, { "Brigadeiro", kMale }, { "Pastelzinho", kAny }, { "Feijoada", kFemale },
        { "Caipirinha", kFemale }, { "Guaraná", kAny }, { "Açaí", kAny }, { "Tapioca", kFemale }, { "Pudim", kAny },
        { "Paçoca", kFemale }, { "Churrasco", kAny }, { "Picanha", kFemale }, { "Farofa", kFemale }, { "Farofeiro", kMale },
        { "Cachaceiro", kMale }, { "Cervejinha", kFemale }, { "Gelada", kFemale }, { "Breja", kFemale }, { "Bolinho", kAny },
        { "Mandioca", kFemale }, { "Pamonha", kFemale }, { "Quindim", kAny }, { "Cuscuz", kAny }, { "Acarajé", kAny },
        { "Moqueca", kFemale }, { "Esfiha", kFemale }, { "Kibe", kAny }, { "Brigadeirão", kMale }, { "Beijinho", kAny },
        { "Cajuzinho", kAny }, { "Rapadura", kFemale }, { "Goiabada", kFemale }, { "Goiabinha", kAny }, { "Caldodecana", kAny },
        { "Pastel", kAny }, { "Xisbacon", kAny }, { "Dogão", kAny }, { "Marmita", kFemale }, { "Pf", kAny },
        // ---- folklore and stories -------------------------------------------------------------------------------------
        { "Saci", kMale }, { "Curupira", kAny }, { "Iara", kFemale }, { "Boitatá", kAny }, { "Cuca", kFemale },
        { "Lobisomem", kMale }, { "Boto", kMale }, { "Macunaíma", kMale }, { "Caipora", kAny }, { "Mapinguari", kAny },
        { "Matinta", kAny }, { "Pererê", kMale }, { "Quibungo", kAny }, { "Mulamanca", kAny }, { "Pisadeira", kFemale },
        { "Cabeçadecuia", kAny }, { "Boibumbá", kAny }, { "Parintins", kAny }, { "Frevo", kAny }, { "Maracatu", kAny },
        { "Sambista", kAny }, { "Pagodeiro", kMale }, { "Forrozeiro", kMale }, { "Sertanejo", kMale }, { "Capoeira", kAny },
    };
    return names;
}

} // namespace Playerbot::V2::Fleet::LocaleNames
