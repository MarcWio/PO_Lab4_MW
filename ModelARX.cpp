#include "ModelARX.h"
#include <math.h>
#include <numeric>
#include <random>

ModelARX::ModelARX(const std::vector<double>& wsp_A, const std::vector<double>& wsp_B, int wart_delay, double odchylenie)
{
	set_A(wsp_A);
	set_B(wsp_B);
	set_delay(wart_delay);
	set_stand(odchylenie);
}


void ModelARX::set_A(std::vector<double> wssp_A)
{
	pam_syg_we.resize(wssp_A.size(), 0.0);

	A_mian = wssp_A;
}

void ModelARX::set_B(std::vector<double> wssp_B)
{
	pam_syg_wyj.resize(wssp_B.size(), 0.0);
	B_licz = wssp_B;
}

void ModelARX::set_delay(int opoznienie_1 = 1)
{
	if (opoznienie_1 < 0) {
		opoznienie = 1;
	}
	else
	{
		opoznienie = opoznienie_1;
	}
	pam_delay_transp.resize(opoznienie - 1, 0.0);
}

void ModelARX::set_stand(double od_stand = 0.0)
{
	if (od_stand < 0.0) {
		odchyl_stand = 0.0;
	}
	else
		odchyl_stand = od_stand;
}

double ModelARX::noise()
{
	//std::random_device gen;
	//std::normal_distribution<> d(0, m_stdev);
	return 0.0;
}

double ModelARX::symuluj(double u)
{
	double y;
	y = std::inner_product(ModelARX::B_licz.begin(), ModelARX::B_licz.end(), ModelARX::pam_syg_we.begin(), 0.0)
		- std::inner_product(ModelARX::A_mian.begin(), ModelARX::A_mian.end(), ModelARX::pam_syg_wyj.begin(), 0.0) + ModelARX::noise();

	ModelARX::pam_delay_transp.push_back(u);
	ModelARX::pam_syg_we.push_front(ModelARX::pam_delay_transp.front());
	ModelARX::pam_delay_transp.pop_front();
	ModelARX::pam_syg_wyj.push_front(y);
	return ModelARX::pam_syg_wyj.front();
}
