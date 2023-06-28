#include <iostream>
#include <cmath>
#include "Dekoratory.h"


double SkokJednostkowy::symuluj(double u) {
    if (u < 0) return 0.0;
    else return 1.0;
}


Dekorator::Dekorator(ObiektSISO* abs_0)
    : m_abs_0(abs_0) {}

double Dekorator::symuluj(double u) {
    return this->m_abs_0->symuluj(u);
}


Sinus::Sinus(ObiektSISO* abs, double amplituda, double czestotliwosc, double phase)
    : Dekorator::Dekorator(abs), m_amplituda(amplituda), m_czestotliwosc(czestotliwosc), m_phase(phase) {}

double Sinus::symuluj(double u) {
    return m_abs_0->symuluj(u) + m_amplituda * std::sin(2.0 * 6.28 * m_czestotliwosc * u + m_phase);
}


Prostok¹t::Prostok¹t(ObiektSISO* abs, double amplituda, double czestotliwosc, double wypelnienie)
    : Dekorator::Dekorator(abs), m_amplituda(amplituda), m_czestotliwosc(czestotliwosc), m_wypelnienie(wypelnienie) {}

double Prostok¹t::symuluj(double u) {
    double period = 1 / m_czestotliwosc;
    double tP = fmod(u, period);
    if (tP < period * m_wypelnienie) return m_abs_0->symuluj(u) + m_amplituda;
    else return m_abs_0->symuluj(u) + 0.0;
}


Szum::Szum(ObiektSISO* abs, double sred, double odchyleniestandardowe)
    : Dekorator::Dekorator(abs), m_sred(sred), m_odchyleniestandardowe(odchyleniestandardowe), generator(std::random_device{}()), dist(sred, odchyleniestandardowe) {}

double Szum::symuluj(double u) {
    generator.seed(u);
    return m_abs_0->symuluj(u) + dist(generator);
}


Trojkat::Trojkat(ObiektSISO* abs, double amplituda, double czestotliwosc, double wypelnienie)
    : Dekorator::Dekorator(abs), m_amplituda(amplituda), m_czestotliwosc(czestotliwosc), m_wypelnienie(wypelnienie) {};

double Trojkat::symuluj(double u) {
    double period = 1 / m_czestotliwosc;
    double a2 = (-m_amplituda / ((1 - m_wypelnienie) * period)), a1 = (m_amplituda / (m_wypelnienie * period));
    double tinp = fmod(u, period);
    if (tinp < period * m_wypelnienie) return m_abs_0->symuluj(u) + a1 * tinp;
    else return m_abs_0->symuluj(u) + a2 * tinp + (m_amplituda / (1 - m_wypelnienie));
};