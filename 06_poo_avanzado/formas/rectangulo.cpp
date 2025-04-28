#include "rectangulo.h"

Rectangulo::Rectangulo()
{

}

double Rectangulo::area()
{
          return(alto*ancho) ;

}

double Rectangulo::getAncho() const
{
    return ancho;
}

void Rectangulo::setAncho(double newAncho)
{
    ancho = newAncho;
}

double Rectangulo::getAlto() const
{
    return alto;
}

void Rectangulo::setAlto(double newAlto)
{
    alto = newAlto;
}
