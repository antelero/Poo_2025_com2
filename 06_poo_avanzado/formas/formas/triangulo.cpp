#include "triangulo.h"
#include "forma.h"

Triangulo::Triangulo( float base,float altura)
{
    this->altura=altura;
    this->base = base;
};


double Triangulo::area()
{
   return(base*altura/2) ;
}
