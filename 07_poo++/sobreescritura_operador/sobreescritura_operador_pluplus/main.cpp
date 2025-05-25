#include "persona.h"

int main() {
    Persona persona("Juan Perez", 30, 25907280);
    Persona persona2("Juan Perez", 30, 25907280);

    Persona persona3("Juan Perez", 30, 49512985);
    std::cout << "Inicial: " << persona << std::endl;

    persona++; // Post-incremento
    std::cout << "Luego del postincremento: "<< persona << std::endl;
    if (persona == persona2)
        std::cout << "Persona 1 y 2 son iguales"<< std::endl;
    if (persona == persona3)
        std::cout << "Persona 1 y 3 son iguales"<< std::endl;
    else
        std::cout << "Persona 1 y 3 son distintas"<< std::endl;
    return 0;
}
