#ifndef GESTORGASTO_H
#define GESTORGASTO_H
#include <iostream>
#include <gasto.h>

#include <gasto.h>

class gestorgasto
{
    Gasto ** gastos=0;
    int cantidad = 0;

public:
    gestorgasto();
    void addGasto(Gasto * gas);
    Gasto* getGasto(int);
    int getCantidad();


};


#endif // GESTORGASTO_H
