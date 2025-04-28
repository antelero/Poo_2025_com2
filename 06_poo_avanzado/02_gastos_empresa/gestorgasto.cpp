#include "gestorgasto.h"
using namespace std;

gestorgasto::gestorgasto()
{

}

void gestorgasto::addGasto(Gasto * gas)
{
    Gasto ** aux = new Gasto*[this->cantidad+1];

    for (int i = 0; i < cantidad; i++) {
         aux[i] = this->gastos[i];
    }
    aux[cantidad] = gas;
    delete [] this->gastos;
    this->gastos = aux;
    this->cantidad++;
}



int gestorgasto::getCantidad()
{
    return this->cantidad;
}

Gasto * gestorgasto::getGasto(int pos)
{
    return gastos[pos];
}
