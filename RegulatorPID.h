
#ifndef REGULATORPID_H
#define REGULATORPID_H

#include "ObiektSISO.h"

class RegulatorPID
    : public ObiektSISO
{
private:
    double k; //proportionalgain
    double Ti; // integralTimeConst
    double calka; //integralTermMem

    void ustaw_dodatnia(double& f, double wart);
    double cz_P(double wejscie);
    double cz_I(double wejscie);
public:
    RegulatorPID(double _k)
        :
        Ti{ 0.0 },
        k{ 0.0 },
        calka{ 0.0 }
    {
        ustaw_wzm(_k);
    }

    RegulatorPID(double _k, double _Ti)
        :
        calka{ 0.0 },
        Ti{ 0.0 }
    {
        ustaw_wzm(_k);
        ustaw_Ti(_Ti);
    }

    ~RegulatorPID() {}

    void ustaw_wzm(double _k);

    void ustaw_Ti(double _Ti);

    double symuluj(double wejscie) override;
};


#endif 
