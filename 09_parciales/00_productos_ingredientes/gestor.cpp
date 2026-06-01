#include "gestor.h"


Gestor::Gestor(const char *nom) {
    strncpy(nombre, nom, 63);
    nombre[63] = '\0';
}

void Gestor::registrarProducto(Producto *p) {
    productos.agregar(p);
}

void Gestor::imprimirCatalogo() const {
    cout << "=== Catalogo de " << nombre << " ===\n\n";
    for (int i = 0; i < productos.size(); i++)
        cout << *productos.obtener(i);
    cout << "\n";
}
