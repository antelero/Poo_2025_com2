#ifndef PERECEDERO_H
#define PERECEDERO_H

#include "producto.h"

class Perecedero : public Producto {
    int dias_a_caducar;

public:
    Perecedero(string n, double p, int d);

    double calcular(int cantidad) const override;
    void imprimir(ostream& os) const override;
    int getDias() const;
};

#endif
