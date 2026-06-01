#ifndef GESTOR_H
#define GESTOR_H


// ------------------------------------------------------------
// Gestor — Catálogo de productos (usa el Vector template)
// Centraliza la gestión; evita lógica en main().
// ------------------------------------------------------------
#include "producto.h"
class Gestor {
private:
    Vector<Producto*> productos;
    char nombre[64];

public:
    Gestor(const char* nom);

    void registrarProducto(Producto* p);

    // Imprime todos los productos con sus ingredientes
    // Aprovecha el operador<< polimórfico de Producto
    void imprimirCatalogo() const;
};


#endif // GESTOR_H
