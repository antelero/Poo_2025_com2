#include "circulo.h"


Circulo::Circulo(double diametro)
{
    this->diametro = diametro;
}

double Circulo::area()
{
    return 3.1416*diametro;
}
