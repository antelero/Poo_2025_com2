#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "forma.h"

class Triangulo : public Forma
{
private:
    double altura=0;
    double base=0;
public:
    Triangulo( float base, float altura);

    double area();
};

#endif // TRIANGULO_H
