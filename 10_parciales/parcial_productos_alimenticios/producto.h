#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string>
#include "vectordinamico.cpp"

class Producto {
protected:
    std::string codigo;
    std::string nombre;

public:
    Producto(const std::string& c, const std::string& n);

    virtual ~Producto() {}

    std::string getCodigo() const;
    std::string getNombre() const;

    virtual VectorDinamico<std::string> getIngredientes() const = 0;

    virtual void imprimir(std::ostream& os) const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Producto& p);

    virtual bool esCompuesto() const = 0;
};

#endif
