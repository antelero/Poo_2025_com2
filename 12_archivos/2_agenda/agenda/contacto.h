#ifndef CONTACTO_H
#define CONTACTO_H
#include <iostream>

class Contacto {
    char tipo[20];
    char valor[50];

public:
    Contacto() {
        tipo[0] = '\0';
        valor[0] = '\0';
    }

    void cargarDesdeTeclado();

    void mostrar() const {
        std::cout << tipo << ": " << valor << std::endl;
    }

    void guardarBinario(std::ofstream& out) const;

    void cargarBinario(std::ifstream& in);
};

#endif // CONTACTO_H
