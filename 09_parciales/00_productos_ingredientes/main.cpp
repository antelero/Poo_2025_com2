#include <iostream>
#include "caja.cpp"   //Al usar la clase template tiene que ir siempore el archivo donde esta la implementacion en este caso .cpp
#include "gestor.h"
#include "productocompuesto.h"
#include "productosimple.h"
using namespace std;

template <typename T>
T maximo(T a, T b) {
    return (a > b) ? a : b;
}

int main()
{
    /*
    // Uso:
    char r3 = maximo('a', 'z');       // T = char
    int r1 = maximo(3, 7);       // T = int
    double r2 = maximo(1.5, 2.3); // T = double
    cout << "int " << r1 << " Doub  " << r2 << " char  " << r3 << endl;

    // Uso:
    Caja<int>  c1(42);
    Caja<string> c2("hola");

    cout << "int " << c1.get() << " Doub  " << c2.get() << endl;
    */

    // --- Productos simples ---
    ProductoSimple sonrisas(101, "Galletitas Sonrisas");
    sonrisas.agregarIngrediente(Ingrediente("Harina"));
    sonrisas.agregarIngrediente(Ingrediente("Azucar"));
    sonrisas.agregarIngrediente(Ingrediente("Leche"));
    sonrisas.agregarIngrediente(Ingrediente("Soja"));
    sonrisas.agregarIngrediente(Ingrediente("Frambuesa"));

    ProductoSimple chocolate(102, "Tableta de Chocolate");
    chocolate.agregarIngrediente(Ingrediente("Cacao"));
    chocolate.agregarIngrediente(Ingrediente("Azucar"));   // duplicado intencional
    chocolate.agregarIngrediente(Ingrediente("Leche"));

    // --- Producto compuesto ---
    ProductoCompuesto diversion(201, "Bolsa Galletitas Diversion");
    diversion.agregarSubproducto(&sonrisas);
    diversion.agregarSubproducto(&chocolate);
    // Ingredientes resultantes (sin duplicados): Harina, Azucar, Leche,
    //   Soja, Frambuesa, Cacao

    // --- Empresa ---
    Gestor empresa("Alimentos SA");
    empresa.registrarProducto(&sonrisas);
    empresa.registrarProducto(&chocolate);
    empresa.registrarProducto(&diversion);

    empresa.imprimirCatalogo();

    // --- Demo Vector: eliminar ocurrencias ---
    cout << "=== Demo Vector::eliminarOcurrencias ===\n";
    Vector<int> v;
    v.agregar(1); v.agregar(3); v.agregar(3); v.agregar(5); v.agregar(3);
    cout << "Antes: ";
    for (int i = 0; i < v.size(); i++) cout << v.obtener(i) << " ";
    v.eliminarOcurrencias(3);
    cout << "\nDespues de eliminar 3s: ";
    for (int i = 0; i < v.size(); i++) cout << v.obtener(i) << " ";
    cout << "\n\n";


    return 0;
}
