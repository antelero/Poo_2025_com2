#ifndef GASTO_H
#define GASTO_H

#include <iostream>
#include <string>

class Gasto
{
protected:
    double importe = 0.0;
public:
    Gasto();
    void setImporte(double importe_);
    double getImporte();

    std::string virtual getDescripcion() = 0;
};

#endif // GASTO_H
