#ifndef PRODUCTOSIMPLE_H
#define PRODUCTOSIMPLE_H

#include "producto.h"
// ------------------------------------------------------------
// ProductoSimple
// Tiene una lista directa de ingredientes (relación "tiene-un").
// ------------------------------------------------------------
class ProductoSimple : public Producto {
private:
    Vector<Ingrediente> ingredientes;   // Composición

public:
    ProductoSimple();

    ProductoSimple(int cod, const char* nom);

    void agregarIngrediente(const Ingrediente& ing);

    // Implementa el contrato de Producto
    Vector<Ingrediente> getIngredientes() const override;
};

#endif // PRODUCTOSIMPLE_H
