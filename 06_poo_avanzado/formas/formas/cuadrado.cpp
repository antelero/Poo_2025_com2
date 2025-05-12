#include "cuadrado.h"

Cuadrado::Cuadrado(double lado)
{
    this->lado = lado;
}

double Cuadrado::area()
{
    return(lado * lado) ;
}
