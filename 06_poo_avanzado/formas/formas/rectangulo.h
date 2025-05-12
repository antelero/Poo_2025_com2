#ifndef RECTANGULO_H
#define RECTANGULO_H

#include "forma.h"

class Rectangulo : public Forma
{
private:
    double alto=0;
    double ancho=0;
public:
    Rectangulo(double alto,double ancho);
    double area();

};

#endif // RECTANGULO_H
