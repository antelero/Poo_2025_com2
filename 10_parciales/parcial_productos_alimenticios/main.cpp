#include <iostream>
#include "producto.h"
#include "productocompuesto.h"
#include "productosimple.h"
#include "vectordinamico.h"

int main() {
    VectorDinamico<int> ints;

    ints.agregar(1);
    ints.agregar(1);
    ints.agregar(3);
    ints.agregar(5);
    ints.agregar(4);
    //Imprime
    for (int i = 0; i < ints.size(); ++i) {
        std::cout << ints[i] << " ";
    }
    std::cout << std::endl;

    ints.eliminarTodas(1);  // Elimina todos los 1
    //Imprime
    for (int i = 0; i < ints.size(); ++i) {
        std::cout << ints[i] << " ";
    }
    // Salida: 3 5 4
    std::cout << std::endl;
    system("pause");


    VectorDinamico<Producto*> productos;

    // Galletitas Sonrisas
    ProductoSimple * galletitas = new ProductoSimple("P001", "Galletitas Sonrisas");
    galletitas->agregarIngrediente("Harina");
    galletitas->agregarIngrediente("Azucar");
    galletitas->agregarIngrediente("Leche");
    galletitas->agregarIngrediente("Frambuesa");
    productos.agregar(galletitas);

    // Galletitas pepas batata
    ProductoSimple* boca_dama = new ProductoSimple("P002", "Boca de Dama");
    boca_dama->agregarIngrediente("Harina");
    boca_dama->agregarIngrediente("Azucar");
    boca_dama->agregarIngrediente("Leche");
    boca_dama->agregarIngrediente("Chocolate");

    productos.agregar(boca_dama);

    // Bolsa de Galletitas Diversión
    ProductoCompuesto* bolsa = new ProductoCompuesto("P003", "Bolsa Galletitas Diversion");
    bolsa->agregarProducto(galletitas); // Contiene galletitas
    bolsa->agregarProducto(boca_dama);
    productos.agregar(bolsa);

    ProductoSimple * anillos = new ProductoSimple("P004", "Galletitas anillos de colores");
    anillos->agregarIngrediente("Harina");
    anillos->agregarIngrediente("Azucar");
    anillos->agregarIngrediente("Leche");
    anillos->agregarIngrediente("Frambuesa");
    productos.agregar(anillos);

    // Mostrar productos
    std::cout << "\n=== Productos cargados ===\n";
    for (int i = 0; i < productos.size(); ++i) {
        std::cout << *productos[i] << "\n";
    }


    std::cout << "Fin" << "\n";


    return 0;
}
