#ifndef CIRCULO_H
#define CIRCULO_H

#include "forma.h"

class Circulo : public Forma
{
private:
    double diametro=0;

public:
    Circulo();
    double area();
    double getDiametro() const;
    void setDiametro(double newDiametro);

};

#endif // CIRCULO_H

