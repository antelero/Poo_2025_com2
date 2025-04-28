#include "triangulo.h"
#include "forma.h"

Triangulo::Triangulo()
{

};

  double Triangulo::getAlto() const
{
    return alto;
}

void Triangulo::setAlto(double newAlto)
{
    alto = newAlto;
}

double Triangulo::getAncho() const
{
    return ancho;
}

void Triangulo::setAncho(double newAncho)
{
    ancho = newAncho;
}

double Triangulo::area()
{
   return(alto*ancho/2) ;
}
