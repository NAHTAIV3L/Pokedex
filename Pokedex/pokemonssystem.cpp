#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <thread>
#include <stdio.h>
#include "sha1.h"

#ifdef _WIN32
    #define CURL_STATICLIB
    #include <Windows.h>
    #include <curl/Win32/curl.h>
    #include <curl/Win32/easy.h>
    #pragma comment(lib, "libcurl.lib")
    #pragma comment(lib, "Normaliz.lib")
    #pragma comment(lib, "Ws2_32.lib")
    #pragma comment(lib, "Wldap32.lib")
    #pragma comment(lib, "Crypt32.lib")
    #pragma comment(lib, "advapi32.lib")
    #define SLEEP(x) Sleep(x)
    #define CLEAR std::system("cls")
#elif __linux__
    #include <curl/curl.h>
    #include <curl/easy.h>
    #include <unistd.h>
    #define SLEEP(x) sleep((x / 1000))
    #define CLEAR std::system("clear")
#endif

void DownloadFile()
{
    CURL* curl; 
    FILE* fp; 
    CURLcode res; 
    const char* url = "https://www.cheru.dev/Pokedex.pkdx"; 
    char outfilename[FILENAME_MAX] = "Pokedex.pkdx"; 
    curl = curl_easy_init(); 
    if (curl) 
    { 
        fp = fopen(outfilename, "wb"); 
        curl_easy_setopt(curl, CURLOPT_URL, url); 
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL); 
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp); 
        res = curl_easy_perform(curl); 
        curl_easy_cleanup(curl); 
        fclose(fp); 
    }
}

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string GetHash()
{
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.cheru.dev/Pokedex.pkdx.hash");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        return readBuffer;
    }
    else
        return "Error";
}

enum type
{
  None = 0, Normal, Fire, Water, Grass,
  Electric, Ice, Fighting, Poison, Ground,
  Flying, Psychic, Bug, Rock, Ghost,
  Dark, Dragon, Steel, Fairy
};

std::string TypeToString(const uint8_t& type)
{
    if      (type == None    ) { return "None";     }
    else if (type == Normal  ) { return "Normal";   }
    else if (type == Fire    ) { return "Fire";     }
    else if (type == Water   ) { return "Water";    }
    else if (type == Grass   ) { return "Grass";    }
    else if (type == Electric) { return "Electric"; }
    else if (type == Ice     ) { return "Ice";      }
    else if (type == Fighting) { return "Fighting"; }
    else if (type == Poison  ) { return "Poison";   }
    else if (type == Ground  ) { return "Ground";   }
    else if (type == Flying  ) { return "Flying";   }
    else if (type == Psychic ) { return "Psychic";  }
    else if (type == Bug     ) { return "Bug";      }
    else if (type == Rock    ) { return "Rock";     }
    else if (type == Ghost   ) { return "Ghost";    }
    else if (type == Dark    ) { return "Dark";     }
    else if (type == Dragon  ) { return "Dragon";   }
    else if (type == Steel   ) { return "Steel";    }
    else if (type == Fairy   ) { return "Fairy";    }
    else                       { return "Error";    }
}

class pokemon
{
public:

    uint64_t PokedexEntry = 0;

    std::string Name;

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
        s += "\n\n    Type 1: ";            s += TypeToString(type1);
        s +=   "\n    Type 2: ";            s += TypeToString(type2);
        s += "\n\n    Total: ";             s += std::to_string(Total);  
        s += "\n        HP: ";              s += std::to_string(HP); 
        s += "\n        Attack: ";          s += std::to_string(Attack);
        s += "\n        Defence: ";         s += std::to_string(Defence); 
        s += "\n        Special Attack: ";  s += std::to_string(Special_Attack); 
        s += "\n        Special Defence: "; s += std::to_string(Special_Defence); 
        s += "\n        Speed: ";           s += std::to_string(Speed); 
        s += "\n\n";
        return s;
    }
};

uint8_t StringToType(const std::string& s)
{
    if (s == "Normal"       ) { return Normal;   }
    else if (s == "Fire"    ) { return Fire;     }
    else if (s == "Water"   ) { return Water;    }
    else if (s == "Grass"   ) { return Grass;    }
    else if (s == "Electric") { return Electric; }
    else if (s == "Ice"     ) { return Ice;      }
    else if (s == "Fighting") { return Fighting; }
    else if (s == "Poison"  ) { return Poison;   }
    else if (s == "Ground"  ) { return Ground;   }
    else if (s == "Flying"  ) { return Flying;   }
    else if (s == "Psychic" ) { return Psychic;  }
    else if (s == "Bug"     ) { return Bug;      }
    else if (s == "Rock"    ) { return Rock;     }
    else if (s == "Ghost"   ) { return Ghost;    }
    else if (s == "Dark"    ) { return Dark;     }
    else if (s == "Dragon"  ) { return Dragon;   }
    else if (s == "Steel"   ) { return Steel;    }
    else if (s == "Fairy"   ) { return Fairy;    }
    else if (s == "None"    ) { return None;     }
    else                      { return NULL;     }
}

void FormatAndPrintLine(const std::string& s)
{
    std::stringstream strs(s);
    std::string val;
    std::vector<std::string> output;
    while (std::getline(strs, val, ' '))
    {
        output.emplace_back(val);
    }

    pokemon p = { (uint64_t)stoi(output[0]),
                  output[1],
                  StringToType(output[2]),
                  StringToType(output[3]),
                  (uint32_t)stoi(output[4]),
                  (uint8_t)stoi(output[5]),
                  (uint8_t)stoi(output[6]),
                  (uint8_t)stoi(output[7]),
                  (uint8_t)stoi(output[8]),
                  (uint8_t)stoi(output[9]),
                  (uint8_t)stoi(output[10]),
    };
    std::cout << "\n" << p.str();
}




int main()
{
    std::ifstream* TestFile = new std::ifstream();
    TestFile->open("Pokedex.pkdx");
    if (TestFile->fail() && !(TestFile->bad()))
    {
        DownloadFile();
    }
    else 
    { 
        std::string WebHash = GetHash();

        std::ifstream file("Pokedex.pkdx");
        std::string string = " ";

        while (!file.eof())
        {
            string += file.get();
        }
        
        SHA1 Hash;
        Hash.update(string);
        std::string FileHash = Hash.final();

        if (FileHash != WebHash)
        {
            std::remove("Pokedex.pkdx");
            DownloadFile();
        }
        else
        {

        }
    }
    delete TestFile;

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
        CLEAR;
        if (TypeSearch == 'e')
        {
            std::cout << "(Must be a number and lower than " << lines <<") Which Pokedex entry do you want: ";
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
            file.close();
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
            file.close();
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
    SLEEP(500);
    return 0;
}
