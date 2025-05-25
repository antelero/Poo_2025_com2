#include "persona.h"

int main() {
    Persona persona("Juan Perez", 30, 25907280);

    std::cout << "Inicial: " << persona << std::endl;

    persona++; // Post-incremento
    std::cout << "Luego del postincremento: "<< persona << std::endl;

    return 0;
}
