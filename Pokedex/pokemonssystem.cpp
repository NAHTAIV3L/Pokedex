#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <Windows.h>

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
        s += "\n        Defence: "; s += std::to_string(Defence); 
        s += "\n        Special Attack: "; s += std::to_string(Special_Attack); 
        s += "\n        Special Defence: "; s += std::to_string(Special_Defence); 
        s += "\n        Speed: "; s += std::to_string(Speed); s += "\n\n";
        return s;
    }
};

uint8_t StringToType(std::string s)
{
    if (s == "Normal")        { return Normal; }
    else if (s == "Fire")     { return Fire; }
    else if (s == "Water")    { return Water; }
    else if (s == "Grass")    { return Grass; }
    else if (s == "Electric") { return Electric; }
    else if (s == "Ice")      { return Ice; }
    else if (s == "Fighting") { return Fighting; }
    else if (s == "Poison")   { return Poison; }
    else if (s == "Ground")   { return Ground; }
    else if (s == "Flying")   { return Flying; }
    else if (s == "Psychic")  { return Psychic; }
    else if (s == "Bug")      { return Bug; }
    else if (s == "Rock")     { return Rock; }
    else if (s == "Ghost")    { return Ghost; }
    else if (s == "Dark")     { return Dark; }
    else if (s == "Dragon")   { return Dragon; }
    else if (s == "Steel")    { return Steel; }
    else if (s == "Fairy")    { return Fairy; }
    else if (s == "None")     { return None; }
    else { return NULL; }
}

void FormatAndPrintLine(std::string& s)
{
    std::stringstream strs(s);
    std::string val;
    std::vector<std::string> output;
    while (std::getline(strs, val, ' '))
    {
        output.emplace_back(val);
    }

    pokemon p = { stoi(output[0]),
                  output[1],
                  StringToType(output[2]),
                  StringToType(output[3]),
                  stoi(output[4]),
                  stoi(output[5]),
                  stoi(output[6]),
                  stoi(output[7]),
                  stoi(output[8]),
                  stoi(output[9]),
                  stoi(output[10]),
    };
    std::cout << "\n" << p.str();
}



int main()
{
    std::ifstream* file = new std::ifstream("Pokedex.pkdx");
    auto lines = std::count(std::istreambuf_iterator<char>(*file), std::istreambuf_iterator<char>(), '\n');
    delete file;
    lines += 2;

    char TypeSearch;
    int PokedexEntry = 0;
    bool PokemonNameFound = true;
    std::string PokemonName;
    while (true)
    {
        std::cout << "Pokedex Entry(e) Name(n) Quit(q) \nWhat Type of Searching Do You Want To Do: ";
        std::cin >> TypeSearch;
        TypeSearch = tolower(TypeSearch);
        std::system("cls");
        if (TypeSearch == 'e')
        {
            std::cout << "(Must Be Lower than " << lines <<") Which Pokedex entry do you want: ";
            std::cin >> PokedexEntry;
            std::ifstream file("Pokedex.pkdx");
            if (file.is_open())
            {
                while (!file.eof())
                {
                    char cs[256];
                    file.getline(cs, 256);
                    std::string s = cs;
                    auto entry_number = s.substr(0, s.find(" "));
                    if (entry_number == std::to_string(PokedexEntry))
                    {
                        FormatAndPrintLine(s);
                        break;
                    }
                    else {}
                }
            }
        }
        else if (TypeSearch == 'n')
        {
            std::cout << "Enter Pokemon Name: ";
            std::cin >> PokemonName;
            std::transform(PokemonName.begin(), PokemonName.end(), PokemonName.begin(), tolower);

            std::ifstream file("Pokedex.pkdx");
            if (file.is_open())
            {
                while (!file.eof())
                {
                    char cs[256];
                    file.getline(cs, 256);
                    std::string s = cs;

                    size_t found = s.find(PokemonName);

                    if (found != std::string::npos)
                    {
                        FormatAndPrintLine(s);
                        PokemonNameFound = true;
                        break;
                    }
                    else
                    {
                        PokemonNameFound = false;
                    }
                }
            }
            if (!PokemonNameFound)
                std::cout << "\n" << "Pokemon Name Not Found" << "\n\n";
            else
            {}
        }
        if (TypeSearch == 'q')
        {
            break;
        }
    }
    std::cout << "\n\n\n\n\n\n\n\n\t\t\t\t\tThank You For Using Pokedex";
    Sleep(5000);
    return 0;
}
