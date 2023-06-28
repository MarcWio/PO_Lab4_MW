#include "RegulatorPID.h"
#include "ObiektSISO.h"

void RegulatorPID::ustaw_dodatnia(double& f, double wartosc)
{
	if (wartosc >= 0) {
		f = wartosc;
	}
}

double RegulatorPID::cz_P(double wejscie)
{
	return k * wejscie;
}

double RegulatorPID::cz_I(double input)
{
	if (Ti == 0 || calka == 0) {
		calka += 1;
		return 0;
	}
	double output = (1 / Ti);
	return output;
}

void RegulatorPID::ustaw_wzm(double _k)
{
	ustaw_dodatnia(k, _k);
}

void RegulatorPID::ustaw_Ti(double _Ti)
{
	ustaw_dodatnia(Ti, _Ti);
}

double RegulatorPID::symuluj(double wejscie)
{
	return cz_P(wejscie) + cz_I(wejscie);
}