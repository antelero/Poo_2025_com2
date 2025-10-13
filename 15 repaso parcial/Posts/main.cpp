#include "gestorblog.h"
#include <iostream>
using namespace std;

int main() {
    GestorBlog gestor;
    gestor.generarDummyPosts();
    // Cargar posts desde archivo binario
    gestor.cargarPosts();

    cout << "\n--- Lista de posts ---\n";
    gestor.mostrarPosts();

    cout << "\n--- Posts ordenados por número de comentarios ---\n";
    gestor.ordenarPorComentarios();
    gestor.mostrarPosts();

    return 0;
}
