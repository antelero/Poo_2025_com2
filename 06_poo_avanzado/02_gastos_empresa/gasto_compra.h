#ifndef GASTO_COMPRA_H
#define GASTO_COMPRA_H
#include <gasto.h>
#include <string>
using namespace std;

class Gasto_Compra: public Gasto
{
     std::string descrProducto;

public:
    Gasto_Compra( std::string descrProducto);
    std::string getDescripcion();
};

#endif // GASTO_COMPRA_H
