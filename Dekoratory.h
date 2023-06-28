#ifndef DEKORATORY_H
#define DEKORATORY_H

#include "ObiektSISO.h" //KOMPONENT
#include <random>

//KOMPONENT KONKRETNY
class SkokJednostkowy : public ObiektSISO {
public:
    SkokJednostkowy() {};
    double symuluj(double u);
};

//DEKORATOR
class Dekorator : public ObiektSISO {
public:
    Dekorator(ObiektSISO* abs_0);
    virtual double symuluj(double u) = 0;
protected:
    ObiektSISO* m_abs_0;
};

//DEKORATOR KONKRETNY SINUS
class Sinus : public Dekorator {
public:
    Sinus(ObiektSISO* abs_1, double amplituda, double czestotliwosc, double phase);
    double symuluj(double u);
private:
    double
        m_amplituda,
        m_czestotliwosc,
        m_phase;
};

//DEKORATOR KONKRETNY PROSTOK¥T
class Prostok¹t : public Dekorator {
public:
    Prostok¹t(ObiektSISO* abs_1, double amplituda, double czestotliwosc, double wypelnienie);
    double symuluj(double u);
private:
    double
        m_amplituda,
        m_czestotliwosc,
        m_wypelnienie;
};

//DEKORATOR KONKRETNY SZUM
class Szum : public Dekorator {
public:
    Szum(ObiektSISO* abs_1, double sred, double odchyleniestandardowe);
    double symuluj(double u);
private:
    double
        m_odchyleniestandardowe,
        m_sred;
    std::default_random_engine generator;
    std::normal_distribution<double> dist;
};

//DEKORATOR KONKRETNY TROJKAT
class Trojkat : public Dekorator {
public:
    Trojkat(ObiektSISO* abs_1, double amplituda, double czestotliwosc, double wypelnienie);
    double symuluj(double u);
private:
    double
        m_amplituda,
        m_czestotliwosc,
        m_wypelnienie;
};

#endif

