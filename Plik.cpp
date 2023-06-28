#include "Plik.h"

nlohmann::json Plik::loadJsonFileConfig()
{

    return this->loadFromFile(this->NazwaPliku, this->lokalizacja);

}

void Plik::createJsonFileConfig(const nlohmann::json& konfiguruj)
{
    StworzPlikJesliNieMa();


    std::ofstream plik(sciezka);
    if (plik.is_open()) {

        plik << konfiguruj.dump(4);

        plik.close();

        std::cout << "\nPlik zapisany" << std::endl;
    }
    else 
        std::cerr << "\nBlad przy zapisie" << std::endl;
    
}

nlohmann::json Plik::loadJsonFileConfig(const Plik& plik)
{

    return this->loadFromFile(plik.NazwaPliku, plik.lokalizacja);

}

Plik::Plik(const std::string& _NazwaPliku, const std::string& _lokalizacja)
    : NazwaPliku(_NazwaPliku), lokalizacja(_lokalizacja)
{

    this->sciezka = _lokalizacja + "/" + _NazwaPliku;

}

bool Plik::LokalizacjaJuzStworzona()
{

    struct stat info;

    if (stat(lokalizacja.c_str(), &info) != 0) {

        return false;
    }
    return (info.st_mode & S_IFDIR) != 0;

}

bool Plik::StworzLokalizacjeJesliNieMa()
{
    int result = _mkdir(lokalizacja.c_str());

    return result == 0;
}

void Plik::JesliJjNadpisz()
{
    std::cout << "\nPlik o nazwie -> '" << sciezka << "' juz istnieje. Czy chcesz go nadpisac? Wybierz (T-TAK/N-NIE): ";

    char choice;

    std::cin >> choice;

    if (choice == 'T' || choice == 't') {
        std::ofstream plik(sciezka);
        if (plik.is_open()) {

            plik.close();

            std::cout << "\nPlik zostal nadpisany: " << NazwaPliku << std::endl;
        }
        else 
            std::cerr << "\nWystapil blad podczas tworzenia pliku!" << sciezka << std::endl;
        
    }
    else 
        exit(0);
    
}

bool Plik::PlikJuzStworzony()
{
    std::ifstream plik(sciezka);

    return plik.good();

}



void Plik::StworzPlikJesliNieMa()
{
    if (!LokalizacjaJuzStworzona()) {

        std::cout << "\nFolder o nazwie ->'" << lokalizacja << "' nie istnieje. Stworzyc go teraz? (T-TAK/N-NIE): ";

        char choice;

        std::cin >> choice;

        if (choice == 'T' || choice == 't') {
            if (!StworzLokalizacjeJesliNieMa()) {

                std::cerr << "\nTworzenie folderu nie powiodlo sie!" << std::endl;

            }
            std::cout << "\nUtworzono folder: " << sciezka << std::endl;
        }
        else 
            exit(0);
        
    }

    if (PlikJuzStworzony()) {

        JesliJjNadpisz();
    }
    else {
        std::ofstream plik(sciezka);

        if (plik.is_open()) {

            plik.close();

            std::cout << "\nUtworzono plik: " << NazwaPliku << std::endl;
        }
        else {

            std::cerr << "\nTworzenie pliku nie powidlo sie!" << sciezka << std::endl;

            exit(0);

        }
    }
}

nlohmann::json Plik::loadFromFile(std::string NazwaPliku, std::string lokalizacja)
{
    std::ifstream plik(lokalizacja + "/" + NazwaPliku);
    if (plik.is_open()) {
        nlohmann::json data;
        plik >> data;
        plik.close();
        return data;
    }
    else {
        std::cerr << "\nOtwarcie pliku nie powiodlo sie!" << std::endl;
    }
}





