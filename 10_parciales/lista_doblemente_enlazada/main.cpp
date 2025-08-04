#include <iostream>
#include "doblementeenlazada.h"

using namespace std;

int main()
{
    DoblementeEnlazada dl;
    dl.addElemento(5);
    dl.addElemento(10);
    dl.addElemento(15);
    dl.addElemento(20);

    std::cout << "Elementos: " << dl.getSize() << std::endl;

    std::cout << "Primero -> ultimo: ";
    dl.impPrimeroUltimo();

    std::cout << "Ultimo -> primero: ";
    dl.impUltimoPrimero();

    return 0;
}
