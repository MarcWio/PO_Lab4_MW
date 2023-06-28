

#ifndef MODELARX_H
#define MODELARX_H

#include <vector>
#include <deque>
#include "ObiektSISO.h"
#include <iostream>
#include <iomanip>





class ModelARX :public ObiektSISO
{

public:
    virtual ~ModelARX() {}
    ModelARX(const std::vector<double>& wsp_A, const std::vector<double>& wsp_B, int wart_delay = 1, double odchylenie = 0.0);

    void set_A(std::vector<double> wssp_A);
    void set_B(std::vector<double> wssp_B);
    void set_delay(int opoznienie_1);
    void set_stand(double od_stand);
    double symuluj(double u);

protected:

    std::vector < double > A_mian;
    std::vector < double > B_licz;
    unsigned int opoznienie;
    double odchyl_stand;
    std::deque < double > pam_syg_we;
    std::deque < double > pam_syg_wyj;
    std::deque < double > pam_delay_transp;

private:
    double noise();

};

#endif

