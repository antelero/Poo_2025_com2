#ifndef CUADRADO_H
#define CUADRADO_H
#include "forma.h"

class Cuadrado : public Forma
{
private:
    double lado=0;
public:
    Cuadrado(double lado);
    double area();
};

#endif // CUADRADO_H
