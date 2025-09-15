#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string>

using namespace std;

// Struct plano para binario
struct ProductoBin {
    char nombre[50];
    double precio;
    int tipo; // 1 = Perecedero, 2 = NoPerecedero
    int dias_a_caducar;
    char tipo_producto[20];
};

class Producto {

private:
    string nombre;
    double precio;

public:
    Producto(string n, double p);
    virtual ~Producto();

    string getNombre() const;
    double getPrecio() const;

    virtual double calcular(int cantidad) const;
    virtual void imprimir(ostream& os) const;

    friend ostream& operator<<(ostream& os, const Producto& p);
};

#endif
