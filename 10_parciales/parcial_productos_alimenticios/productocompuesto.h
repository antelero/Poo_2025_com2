#ifndef PRODUCTOCOMPUESTO_H
#define PRODUCTOCOMPUESTO_H

#include "Producto.h"

class ProductoCompuesto : public Producto {
private:
    VectorDinamico<Producto*> subproductos;

public:
    ProductoCompuesto(const std::string& c, const std::string& n);

    void agregarProducto(Producto* p);

    VectorDinamico<std::string> getIngredientes() const override;

    void imprimir(std::ostream& os) const override;

    bool esCompuesto() const override;
};

#endif
