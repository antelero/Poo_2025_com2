#ifndef ORACION_H
#define ORACION_H

#include <iostream>
using namespace std;


class Oracion
{
private:
    char * oracion;

public:
    Oracion(char * orac);
    int getCantidad() const;
    int getCantLetras() const;
    char *getOracion() const;

    friend ostream& operator<<(ostream& os, const Oracion& oraci);
};

#endif // ORACION_H
