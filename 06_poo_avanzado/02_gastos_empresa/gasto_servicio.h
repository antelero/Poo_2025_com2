#ifndef GASTO_SERVICIO_H
#define GASTO_SERVICIO_H
#include <gasto.h>
#include <string>
using namespace std;
class Gasto_Servicio:public Gasto
{
    std::string descrServ;

public:
    Gasto_Servicio( std::string descrServ);
    std::string getDescripcion();
};

#endif // GASTO_SERVICIO_H
