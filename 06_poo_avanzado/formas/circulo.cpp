#include "circulo.h"


Circulo::Circulo()
{

}

double Circulo::area()
{
    return 3.1416*diametro;
}

double Circulo::getDiametro() const
{
    return diametro;
}

void Circulo::setDiametro(double newDiametro)
{
    diametro = newDiametro;
}
