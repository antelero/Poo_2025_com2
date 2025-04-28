#ifndef RECTANGULO_H
#define RECTANGULO_H

#include "forma.h"

class Rectangulo : public Forma
{
public:
    Rectangulo();
private:
    double alto=0;
    double ancho=0;
public:
    Rectangulo(double,double);
    double area();
    double getAlto() const;
    void setAlto(double newAlto);
    double getAncho() const;
    void setAncho(double newAncho);
};

#endif // RECTANGULO_H
