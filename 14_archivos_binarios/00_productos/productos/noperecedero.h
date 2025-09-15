#ifndef NOPERECEDERO_H
#define NOPERECEDERO_H

#include "producto.h"

class NoPerecedero : public Producto {
    string tipo;

public:
    NoPerecedero(string n, double p, string t);

    double calcular(int cantidad) const override;
    void imprimir(ostream& os) const override;
    const string &getTipo() const;
};

#endif
