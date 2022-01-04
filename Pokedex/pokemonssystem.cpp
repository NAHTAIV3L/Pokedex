#include <string>
#include <iostream>
#include <algorithm>

enum type
{
  None = 0,
  Normal,
  Fire,
  Water,
  Grass,
  Electric,
  Ice,
  Fighting,
  Poison,
  Ground,
  Flying,
  Psychic,
  Bug,
  Rock,
  Ghost,
  Dark,
  Dragon,
  Steel,
  Fairy
};

class pokemon
{
public:

    uint8_t PokedexEntry = 0;

    std::string Name = "You Idiot";

    uint8_t type1 = None;
    uint8_t type2 = None;

    uint32_t Total = 0;
    uint8_t HP = 0;
    uint8_t Attack = 0;
    uint8_t Defence = 0;
    uint8_t Special_Attack = 0;
    uint8_t Special_Defence = 0;
    uint8_t Speed = 0;

    std::string str()
    {
        std::string s = (std::to_string(PokedexEntry) + ". " + Name);
        s += "\n\n    Type 1: ";
        if (type1 == None) { s += "None"; }
        else if (type1 == Normal) { s += "Normal"; }
        else if (type1 == Fire) { s += "Fire"; }
        else if (type1 == Water) { s += "Water"; }
        else if (type1 == Grass) { s += "Grass"; }
        else if (type1 == Electric) { s += "Electric"; }
        else if (type1 == Ice) { s += "Ice"; }
        else if (type1 == Fighting) { s += "Fighting"; }
        else if (type1 == Poison) { s += "Poison"; }
        else if (type1 == Ground) { s += "Ground"; }
        else if (type1 == Flying) { s += "Flying"; }
        else if (type1 == Psychic) { s += "Psychic"; }
        else if (type1 == Bug) { s += "Bug"; }
        else if (type1 == Rock) { s += "Rock"; }
        else if (type1 == Ghost) { s += "Ghost"; }
        else if (type1 == Dark) { s += "Dark"; }
        else if (type1 == Dragon) { s += "Dragon"; }
        else if (type1 == Steel) { s += "Steel"; }
        else if (type1 == Fairy) { s += "Fairy"; }
        s += ("\n    Type 2: ");
        if (type2 == None) { s += "None"; }
        else if (type2 == Normal) { s += "Normal"; }
        else if (type2 == Fire) { s += "Fire"; }
        else if (type2 == Water) { s += "Water"; }
        else if (type2 == Grass) { s += "Grass"; }
        else if (type2 == Electric) { s += "Electric"; }
        else if (type2 == Ice) { s += "Ice"; }
        else if (type2 == Fighting) { s += "Fighting"; }
        else if (type2 == Poison) { s += "Poison"; }
        else if (type2 == Ground) { s += "Ground"; }
        else if (type2 == Flying) { s += "Flying"; }
        else if (type2 == Psychic) { s += "Psychic"; }
        else if (type2 == Bug) { s += "Bug"; }
        else if (type2 == Rock) { s += "Rock"; }
        else if (type2 == Ghost) { s += "Ghost"; }
        else if (type2 == Dark) { s += "Dark"; }
        else if (type2 == Dragon) { s += "Dragon"; }
        else if (type2 == Steel) { s += "Steel"; }
        else if (type2 == Fairy) { s += "Fairy"; }
        s += "\n\n    Total: "; s += std::to_string(Total);  
        s += "\n        HP: "; s += std::to_string(HP); 
        s += "\n        Attack: "; s += std::to_string(Attack);
        s += "\n        Defence:; "; s += std::to_string(Defence); 
        s += "\n        Special Attack: "; s += std::to_string(Special_Attack); 
        s += "\n        Special Defence: "; s += std::to_string(Special_Defence); 
        s += "\n        Speed: "; s += std::to_string(Speed); s += "\n\n";
        return s;
    }
};


int main()
{
    uint8_t IndexSize = 256;
    pokemon index[256];
    index[0] =   { 1, "bulbasaur", Grass, Poison, 318, 45, 49, 49, 65, 65, 45 };
    index[1] =   { 2, "ivysaur", Grass, Poison, 405, 60, 62, 63, 80, 80, 60 };
    index[2] =   { 3, "venusaur", Grass, Poison, 525, 80, 82, 83, 100, 100, 80 };
    index[3] =   { 4, "charmander", Fire, None, 309, 39, 52, 43, 60, 50, 65 };
    index[4] =   { 5, "charmeleon", Fire, None, 405, 58, 64, 58, 80, 65, 80 };
    index[5] =   { 6, "charizard", Fire, Flying, 534, 78, 84, 78, 109, 85, 100 };
    index[6] =   { 7, "squirtle", Water, None, 314, 44, 48, 65, 50, 64, 43 }; 
    index[7] =   { 8, "wartortle", Water, None, 405, 59, 63, 80, 65, 80, 58 };
    index[8] =   { 9, "blastoise", Water, None, 530, 79, 83, 100, 85, 105, 78 };
    index[9] =   { 10, "caterpie", Bug, None, 195, 45, 30, 35, 20, 20, 45 };
    index[10] =  { 11, "metapod", Bug, None, 205, 50, 20, 55, 25, 25, 30 };
    index[11] =  { 12, "butterfree", Bug, Flying, 395, 60, 45, 50, 90, 80, 70 };
    index[12] =  { 13, "weedle", Bug, Poison, 195, 40, 35, 30, 20, 20, 50 };
    index[13] =  { 14, "kakuna", Bug, Poison, 205, 45, 25, 50, 25, 25, 35 };
    index[14] =  { 15, "beedrill", Bug, Poison, 395, 65, 90, 40, 45, 80, 75 };
    index[15] =  { 16, "pidgey", Normal, Flying, 251, 40, 45, 40, 35, 35, 56 };
    index[16] =  { 17, "pidgeotto", Normal, Flying, 349, 63, 60, 55, 50, 50, 71 };
    index[17] =  { 18, "pidgeot", Normal, Flying, 479, 83, 80, 75, 70, 70, 101 };
    index[18] =  { 19, "rattata", Normal, None, 253, 30, 56, 35, 25, 35, 72 };
    index[19] =  { 20, "raticate", Normal, None, 413, 55, 81, 60, 50, 70, 97 };
    index[20] =  { 21, "spearow", Normal, Flying, 262, 40, 60, 30, 31, 31, 70 };
    index[21] =  { 22, "fearow", Normal, Flying, 442, 65, 90, 65, 61, 61, 100 };
    index[22] =  { 23, "ekans", Poison, None, 288, 35, 60, 44, 40, 54, 55 };
    index[23] =  { 24, "arbok", Poison, None, 448, 60, 95, 69, 65, 79, 80 };
    index[24] =  { 25, "pikachu", Electric, None, 320, 35, 55, 40, 50, 50, 90 };
    index[25] =  { 26, "raichu", Electric, None, 485, 60, 90, 55, 90, 80, 110 };
    index[26] =  { 27, "sandshrew", Ground, None, 300, 50, 75, 85, 20, 30, 40 };
    index[27] =  { 28, "sandslash", Ground, None, 450, 75, 100, 110, 45, 55, 65 };
    index[28] =  { 29, "female nidoran", Poison, None, 275, 55, 47, 52, 40, 40, 41 };
    index[29] =  { 30, "nidorina", Poison, None, 365, 70, 62, 67, 55, 55, 56 };
    index[30] =  { 31, "nidoqueen", Poison, Ground, 505, 90, 92, 87, 75, 85, 76 };
    index[31] =  { 32, "male nidoran", Poison, None, 273, 46, 57, 40, 40, 40, 50 };
    index[32] =  { 33, "nidorino", Poison, None, 365, 61, 72, 57, 55, 55, 65 };
    index[33] =  { 34, "nidoking", Poison, Ground, 505, 81, 102, 77, 85, 75, 85 };
    index[34] =  { 35, "clefairy", Fairy, None, 323, 70, 45, 48, 60, 65, 35 };
    index[35] =  { 36, "clefable", Fairy, None, 483, 95, 70, 73, 95, 90, 60 };
    index[36] =  { 37, "vulpix", Fire, None, 299, 38, 41, 40, 50, 65, 65 };
    index[37] =  { 38, "ninetales", Fire, None, 505, 73, 76, 75, 81, 100, 100 };
    index[38] =  { 39, "jigglypuff", Normal, Fairy, 270, 115, 45, 20, 45, 25, 20 };
    index[39] =  { 40, "wigglytuff", Normal, Fairy, 435, 140, 70, 45, 85, 50, 45 };
    index[40] =  { 41, "zubat", Poison, Flying, 245, 40, 45, 35, 30, 40, 55 };
    index[41] =  { 42, "golbat", Poison, Flying, 455, 75, 80, 70, 65, 75, 90 };
    index[42] =  { 43, "oddish", Grass, Poison, 320, 45, 50, 55, 75, 65, 30 };
    index[43] =  { 44, "gloom", Grass, Poison, 395, 60, 65, 70, 85, 75, 40 };
    index[44] =  { 45, "vileplume", Grass, Poison, 490, 75, 80, 85, 110, 90, 50 };
    index[45] =  { 46, "paras", Bug, Grass, 285, 35, 70, 55, 45, 55, 25 };
    index[46] =  { 47, "parasect", Bug, Grass, 405, 60, 95, 80, 60, 80, 30 };
    index[47] =  { 48, "venonat", Bug, Poison, 305, 60, 55, 50, 40, 55, 45 };
    index[48] =  { 49, "venomoth", Bug, Poison, 450, 70, 65, 60, 90, 75, 90 };
    index[49] =  { 50, "diglett", Ground, None, 265, 10, 55, 25, 35, 45, 95 };
    index[50] =  { 51, "dugtrio", Ground, None, 425, 35, 100, 50, 50, 70, 120 };
    index[51] =  { 52, "meowth", Normal, None, 290, 40, 45, 35, 40, 40, 90 };
    index[52] =  { 53, "persian", Normal, None, 440, 65, 70, 60, 65, 65, 115 };
    index[53] =  { 54, "psyduck", Water, None, 320, 50, 52, 48, 65, 50, 55 };
    index[54] =  { 55, "golduck", Water, None, 500, 80, 82, 78, 95, 80, 85 };
    index[55] =  { 56, "mankey", Fighting, None, 305, 40, 80, 35, 35, 45, 70 };
    index[56] =  { 57, "primeape", Fighting, None, 455, 65, 105, 60, 60, 70, 95 };
    index[57] =  { 58, "growlithe", Fire, None, 350, 55, 70, 45, 70, 50, 60 };
    index[58] =  { 59, "arcanine", Fire, None, 555, 90, 110, 80, 100, 80, 95 };
    index[59] =  { 60, "poliwag", Water, None, 300, 40, 50, 40, 40, 40, 90 };
    index[60] =  { 61, "poliwhirl", Water, None, 385, 65, 65, 65, 50, 50, 90 };
    index[61] =  { 62, "poliwrath", Water, Fighting, 510, 90, 95, 95, 70, 90, 70 };
    index[62] =  { 63, "abra", Psychic, None, 310, 25, 20, 15, 105, 55, 90 };
    index[63] =  { 64, "kadabra", Psychic, None, 400, 40, 35, 30, 120, 70, 105 };
    index[64] =  { 65, "alakazam", Psychic, None, 500, 55, 50, 45, 135, 95, 120 };
    index[65] =  { 66, "machop", Fighting, None, 305, 70, 80, 50, 35, 35, 35 };
    index[66] =  { 67, "machoke", Fighting, None, 405, 80, 100, 70, 50, 60, 45 };
    index[67] =  { 68, "machamp", Fighting, None, 505, 90, 130, 80, 65, 85, 55 };
    index[68] =  { 69, "bellsprout", Grass, Poison, 300, 50, 75, 35, 70, 30, 40 };
    index[69] =  { 70, "weepinbell", Grass, Poison, 390, 65, 90, 50, 85, 45, 55 };
    index[70] =  { 71, "victreebel", Grass, Poison, 490, 80, 105, 65, 100, 70, 70 };
    index[71] =  { 72, "tentacool", Water, Poison, 335, 40, 40, 35, 50, 100, 70 };
    index[72] =  { 73, "tentacruel", Water, Poison, 515, 80, 70, 65, 80, 120, 100 };
    index[73] =  { 74, "geodude", Rock, Ground, 300, 40, 80, 100, 30, 30, 20 };
    index[74] =  { 75, "graveler", Rock, Ground, 390, 55, 95, 115, 45, 45, 35 };
    index[75] =  { 76, "golem", Rock, Ground, 495, 80, 120, 130, 55, 65, 45 };
    index[76] =  { 77, "ponyta", Fire, None, 410, 50, 85, 55, 65, 65, 90 };
    index[77] =  { 78, "rapidash", Fire, None, 500, 65, 100, 70, 80, 80, 105 };
    index[78] =  { 79, "slowpoke", Water, Psychic, 315, 90, 65, 65, 40, 40, 15 };
    index[79] =  { 80, "slowbro", Water, Psychic, 490, 95, 75, 110, 100, 80, 30 };
    index[80] =  { 81, "magnemite", Electric, Steel, 325, 25, 35, 70, 95, 55, 45 };
    index[81] =  { 82, "magneton", Electric, Steel, 465, 50, 60, 95, 120, 70, 70 };
    index[82] =  { 83, "farfetch'd", Normal, Flying, 377, 52, 90, 55, 58, 62, 60 };
    index[83] =  { 84, "doduo", Normal, Flying, 310, 35, 85, 45, 35, 35, 75 };
    index[84] =  { 85, "dodrio", Normal, Flying, 470, 60, 110, 70, 60, 60, 110 };
    index[85] =  { 86, "seel", Water, None, 325, 65, 45, 55, 45, 70, 45 };
    index[86] =  { 87, "dewgong", Water, Ice, 475, 90, 70, 80, 70, 95, 70 };
    index[87] =  { 88, "grimer", Poison, None, 325, 80, 80, 50, 40, 50, 25 };
    index[88] =  { 89, "muk", Poison, None, 500, 105, 105, 75, 65, 100, 50 };
    index[89] =  { 90, "shellder", Water, None, 305, 30, 65, 100, 45, 25, 40 };
    index[90] =  { 91, "cloyster", Water, Ice, 525, 50, 95, 180, 85, 45, 70 };
    index[91] =  { 92, "gastly", Ghost, Poison, 310, 30, 35, 30, 100, 35, 80 };
    index[92] =  { 93, "haunter", Ghost, Poison, 405, 45, 50, 45, 115, 55, 95 };
    index[93] =  { 94, "gengar", Ghost, Poison, 500, 60, 65, 60, 130, 75, 110 };
    index[94] =  { 95, "onix", Rock, Ground, 385, 35, 45, 160, 30, 45, 70 };
    index[95] =  { 96, "drowzee", Psychic, None, 328, 60, 48, 45, 43, 90, 42 };
    index[96] =  { 97, "hypno", Psychic, None, 483, 85, 73, 70, 73, 115, 67 };
    index[97] =  { 98, "krabby", Water, None, 325, 30, 105, 90, 25, 25, 50 };
    index[98] =  { 99, "kingler", Water, None, 475, 55, 130, 115, 50, 50, 75 };
    index[99] =  { 100, "voltorb", Electric, None, 330, 40, 30, 50, 55, 55, 100 };
    index[100] = { 101, "electrode", Electric, None, 490, 60, 50, 70, 80, 80, 150 };
    index[101] = { 102, "exeggcute", Grass, Psychic, 60, 40, 80, 60, 45, 40 };
    index[102] = { 103, "exeggutor", Grass, Psychic, 530, 95, 95, 85, 125, 75, 55 };
    index[103] = { 104, "cubone", Ground, None, 320, 50, 50, 95, 40, 50, 35 };
    index[104] = { 105, "marowak", Ground, None, 425, 60, 80, 110, 50, 80, 45 };
    index[105] = { 106, "hitmonlee", Fighting, None, 455, 50, 120, 53, 35, 110, 87 };
    index[106] = { 107, "hitmonchan", Fighting, None, 455, 50, 105, 79, 35, 110, 76 };
    index[107] = { 108, "lickitung", Normal, None, 385, 90, 55, 75, 60, 75, 30 };
    index[108] = { 109, "koffing", Poison, None, 340, 40, 65, 95, 60, 45, 35 };
    index[109] = { 110, "weezing", Poison, None, 490, 65, 90, 120, 85, 70, 60 };
    index[110] = { 111, "rhyhorn", Ground, Rock, 345, 80, 85, 95, 30, 30, 25 };
    index[111] = { 112, "rydon", Ground, Rock, 105, 130, 120, 45, 45, 40 };
    index[112] = { 113, "chansey", Normal, None, 450, 250, 5, 5, 35, 105, 50 };
    index[113] = { 114, "tangela", Grass, None, 435, 65, 55, 115, 100, 40, 60 };
    index[114] = { 115, "kangaskhan", Normal, None, 490, 105, 95, 80, 40, 80, 90 };
    index[115] = { 116, "horsea", Water, None, 295, 30, 40, 70, 70, 25, 60 };
    index[116] = { 117, "seadra", Water, None, 440, 55, 65, 95, 95, 45, 85 };
    index[117] = { 118, "goldeen", Water, None, 320, 45, 67, 60, 35, 50, 63 };
    index[118] = { 119, "seaking", Water, None, 450, 80, 92, 65, 65, 80, 68 };
    index[119] = { 120, "staryu", Water, None, 340, 30, 45, 55, 70, 55, 85 };
    index[120] = { 121, "starmie", Water, Psychic, 520, 60, 75, 85, 100, 85, 115 };
    index[121] = { 122, "mr. mime", Psychic, Fairy, 460, 40, 45, 65, 100, 120, 90 };
    index[122] = { 123, "scyther", Bug, Flying, 500, 70, 110, 80, 55, 80, 105 };
    index[123] = { 124, "jynx", Ice, Psychic, 455, 65, 50, 35, 115, 95, 95 };
    index[124] = { 125, "electabuzz", Electric, None, 490, 65, 83, 57, 95, 85, 105 };
    index[125] = { 126, "magmar", Fire, None, 495, 65, 95, 57, 100, 85, 93 };
    index[126] = { 127, "pinsir", Bug, None, 500, 65, 125, 100, 55, 70, 85 };
    index[127] = { 128, "tauros", Normal, None, 490, 75, 100, 95, 40, 70, 110 };
    index[128] = { 129, "magikarp", Water, None, 200, 20, 10, 55, 15, 20, 80 };
    index[129] = { 130, "gyarados", Water, Flying, 540, 95, 125, 79, 60, 100, 81 };
    index[130] = { 131, "lapras", Water, Ice, 535, 130, 85, 80, 85, 95, 60 };
    index[131] = { 132, "ditto", Normal, None, 288, 48, 48, 48, 48, 48, 48 };
    index[132] = { 133, "eevee", Normal, None, 325, 55, 55, 50, 45, 65, 55 };
    index[133] = { 134, "vaporeon", Water, None, 525, 130, 65, 60, 110, 95, 65 };
    index[134] = { 135, "jolteon", Electric, None, 525, 65, 65, 60, 110, 95, 130 };
    index[135] = { 136, "flareon", Fire, None, 525, 65, 130, 60, 95, 110, 65 };
    index[136] = { 137, "porygon", Normal, None, 395, 65, 60, 70, 85, 75, 40 };
    index[137] = { 138, "omanyte", Rock, Water, 355, 35, 40, 100, 90, 55, 35 };
    index[138] = { 139, "omastar", Rock, Water, 495, 70, 60, 125, 115, 70, 55 };
    index[139] = { 140, "kabuto", Rock, Water, 355, 30, 80, 90, 55, 45, 55 };
    index[140] = { 141, "kabutops", Rock, Water, 495, 60, 115, 105, 65, 70, 80 };
    index[141] = { 142, "aerodactyl", Rock, Flying, 515, 80, 105, 65, 60, 75, 130 };
    index[142] = { 143, "snorlax", Normal, None, 540, 160, 110, 65, 65, 110, 30 };
    index[143] = { 144, "articuno", Ice, Flying, 580, 90, 85, 100, 95, 125, 85 };
    index[144] = { 145, "zapdos", Electric, Flying, 580, 90, 90, 85, 125, 90, 100 };
    index[145] = { 146, "moltres", Fire, Flying, 580, 90, 100, 90, 125, 85, 90 };
    index[146] = { 147, "dratini", Dragon, None, 300, 41, 64, 45, 50, 50, 50 };
    index[147] = { 148, "dragonair", Dragon, None, 420, 61, 84, 65, 70, 70, 70 };
    index[148] = { 149, "dragonite", Dragon, Flying, 600, 91, 134, 95, 100, 100, 80 };
    index[159] = { 150, "mewtwo", Psychic, None, 680, 106, 110, 90, 154, 90, 130 };
    index[150] = { 151, "mew", Psychic, None, 600, 100, 100, 100, 100, 100, 100 };
    char TypeSearch;
    int PokedexEntry = 0;
    bool PokemonNameFound;
    std::string PokemonName;
    while (true)
    {
        std::cout << "Pokedex Entry(e) Name(n) Quit(q) \nWhat Type of Searching Do You Want To Do: ";
        std::cin >> TypeSearch;
        TypeSearch = tolower(TypeSearch);
        std::system("cls");
        if (TypeSearch == 'e')
        {
            std::cout << "(Must Be Lower than 152) Which Pokedex entry do you want: ";
            std::cin >> PokedexEntry;
            std::cout << "\n" << index[(PokedexEntry - 1)].str();
        }
        else if (TypeSearch == 'n')
        {
            std::cout << "Enter Pokemon Name: ";
            std::cin >> PokemonName;
            std::transform(PokemonName.begin(), PokemonName.end(), PokemonName.begin(), tolower);
            for (auto p : index)
            {
                if(p.Name == PokemonName)
                {
                    std::cout << "\n" << p.str();
                    PokemonNameFound = true;
                    break;
                }
                else 
                {
                    PokemonNameFound = false;
                }
            }
            if (!PokemonNameFound)
                std::cout << "\n\nPokemon: " << PokemonName << " Not in Pokedex\n\n\n";
        }
        if (TypeSearch == 'q')
        {
            break;
        }
      
    }

    return 0;
}
