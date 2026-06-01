#include "productosimple.h"

ProductoSimple::ProductoSimple() {}

ProductoSimple::ProductoSimple(int cod, const char *nom)
    : Producto(cod, nom) {}

void ProductoSimple::agregarIngrediente(const Ingrediente &ing) {
    ingredientes.agregar(ing);
}

Vector<Ingrediente> ProductoSimple::getIngredientes() const {
    return ingredientes;
}
