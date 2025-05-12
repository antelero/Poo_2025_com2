#include "rectangulo.h"


Rectangulo::Rectangulo(double alto, double ancho)
{
    this->alto = alto;
    this->ancho = ancho;
}

double Rectangulo::area()
{
    return(alto*ancho) ;
}
