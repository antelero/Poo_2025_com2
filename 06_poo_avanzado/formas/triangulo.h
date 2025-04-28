#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "forma.h"

class Triangulo : public Forma
{
private:
    double alto=0;
    double ancho=0;
public:
    Triangulo();
    double area();
    double getAlto() const;
    void setAlto(double newAlto);
    double getAncho() const;
    void setAncho(double newAncho);
};

#endif // TRIANGULO_H
