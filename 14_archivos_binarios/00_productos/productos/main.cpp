#include <iostream>
#include "producto.h"
#include "gestor.h"
#include "producto.h"
#include "noperecedero.h"
#include "perecedero.h"

#include <iostream>

using namespace std;

int main() {
    Gestor g;

    g.agregarProducto(new Perecedero("Leche", 1.20, 1));
    g.agregarProducto(new Perecedero("Yogur", 0.80, 2));
    g.agregarProducto(new Perecedero("Carne", 5.50, 3));
    g.agregarProducto(new Perecedero("Pan", 1.00, 5));
    g.agregarProducto(new NoPerecedero("Arroz", 2.50, "Grano"));
    g.agregarProducto(new NoPerecedero("Azucar", 1.80, "Dulce"));
    g.agregarProducto(new NoPerecedero("Aceite", 3.20, "Liquido"));

    g.mostrarTodos(5);
    cout << "\n=== Consultas individuales ===" << endl;
    g.consultarProducto("Yogur", 5);
    g.consultarProducto("Carne", 10);
    g.consultarProducto("Chocolate", 2); // no existe

    g.guardarArchi();
    g.limpiar();
    cout << "\n=== Guardo y limpio(size): "<< g.getSize() <<" ===" << endl;

    g.mostrarTodos(5);
    g.leerArchi();
    cout << "\n=== Productos de archivo ===" << endl;
    g.mostrarTodos(5);
    g.obtenerTresCaros();
    g.conteoPorTipo();
    return 0;
}
