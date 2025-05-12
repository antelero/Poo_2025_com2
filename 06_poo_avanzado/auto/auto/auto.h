#ifndef AUTO_H
#define AUTO_H
#include "motor.h"
#include "rueda.h"

class Auto
{
private:
    Motor* motor; // Composición: el motor vive y muere con el auto
    Rueda* ruedas[4]; // Agregación: las ruedas pueden venir de afuera
public:
    Auto(int hp, Rueda *r[]);
    void arrancar();
};

#endif // AUTO_H
