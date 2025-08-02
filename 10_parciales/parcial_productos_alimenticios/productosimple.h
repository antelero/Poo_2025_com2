#ifndef PRODUCTOSIMPLE_H
#define PRODUCTOSIMPLE_H

#include "Producto.h"

class ProductoSimple : public Producto {
private:
    VectorDinamico<std::string> ingredientes;

public:
    ProductoSimple(const std::string& c, const std::string& n);

    void agregarIngrediente(const std::string& ing);

    VectorDinamico<std::string> getIngredientes() const override;

    void imprimir(std::ostream& os) const override;

    bool esCompuesto() const override;
};

#endif
