#ifndef PLIK_H
#define PLIK_H

#include "direct.h"
#include <sys/stat.h>
#include <iostream>
#include "json.hpp"
#include <fstream>
#include <string>

class Plik {
private:

    std::string NazwaPliku;
    std::string lokalizacja; // Folder z plikiem
    std::string sciezka; // Nazwa samego pliku z rozszerzeniem np konfiguracja.json


    bool PlikJuzStworzony(); 
    bool LokalizacjaJuzStworzona();

    bool StworzLokalizacjeJesliNieMa(); // Spr czy jest lokalizacja i tworzy
    void StworzPlikJesliNieMa(); // Spr czy plik istnieje i tworzy

    void JesliJjNadpisz(); // W przypadku gdy plik juz istnieje to nadpisz

    nlohmann::json loadFromFile(std::string NazwaPliku, std::string lokalizacja);


public:
    void createJsonFileConfig(const nlohmann::json& konfiguruj);

    Plik(const std::string& _NazwaPliku, const std::string& _lokalizacja);

    nlohmann::json loadJsonFileConfig();

    nlohmann::json loadJsonFileConfig(const Plik& plik);
};

#endif
