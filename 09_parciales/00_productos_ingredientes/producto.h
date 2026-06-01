#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>
#include "ingrediente.h"
#include "vector.cpp"
// ------------------------------------------------------------
// Clase abstracta Producto
// Representa la interfaz común de cualquier producto.
// Es abstracta porque getIngredientes() no puede implementarse
// sin conocer si el producto es simple o compuesto.
// ------------------------------------------------------------
class Producto {
protected:
    int  codigo;
    char nombre[64];

public:
    Producto();

    Producto(int cod, const char* nom);

    virtual ~Producto() {}

    int         getCodigo()  const;
    const char* getNombre()  const;

    // Método abstracto: cada subclase sabe cómo devolver sus ingredientes
    virtual Vector<Ingrediente> getIngredientes() const = 0;

    // Hook virtual: las subclases pueden agregar líneas extra al imprimir.
       // ProductoSimple no lo necesita; ProductoCompuesto lo sobreescribe.
       virtual void imprimirDetalle(ostream& os) const;

       friend ostream& operator<<(ostream& os, const Producto& p);

};
#endif // PRODUCTO_H
