#include <iostream>
#include "doblementeenlazada.cpp"

using namespace std;

int main()
{
    DoblementeEnlazada<int> deint;
    deint.addElemento(5);
    deint.addElemento(10);
    deint.addElemento(15);
    deint.addElemento(20);

    std::cout << "Elementos: " << deint.getSize() << std::endl;

    std::cout << "Primero -> ultimo: ";
    deint.impPrimeroUltimo();

    std::cout << "Ultimo -> primero: ";
    deint.impUltimoPrimero();

    DoblementeEnlazada<char> dechar;
    dechar.addElemento('a');
    dechar.addElemento('b');
    dechar.addElemento('c');
    dechar.addElemento('d');

    std::cout << "Elementos: " << dechar.getSize() << std::endl;

    std::cout << "Primero -> ultimo: ";
    dechar.impPrimeroUltimo();

    std::cout << "Ultimo -> primero: ";
    dechar.impUltimoPrimero();
    return 0;
}
