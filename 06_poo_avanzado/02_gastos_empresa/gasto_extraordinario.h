#ifndef GASTO_EXTRAORDINARIO_H
#define GASTO_EXTRAORDINARIO_H
#include <gasto.h>
#include <string>
using namespace std;
class Gasto_Extraordinario: public Gasto
{
    std::string descrExtra;

public:
    Gasto_Extraordinario( std::string descrExtra);
    std::string getDescripcion();
};

#endif // GASTO_EXTRAORDINARIO_H
