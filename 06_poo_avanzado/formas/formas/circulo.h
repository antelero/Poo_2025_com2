#ifndef CIRCULO_H
#define CIRCULO_H

#include "forma.h"

class Circulo : public Forma
{
private:
    double diametro=0;

public:
    Circulo(double diametro);
    double area();


};

#endif // CIRCULO_H

