#include "contacto.h"

void Contacto::cargarDesdeTeclado() {
    std::cout << "Tipo de contacto (email, celular, etc.): ";
    std::cin.getline(tipo, 20);
    std::cout << "Valor del contacto: ";
    std::cin.getline(valor, 50);
}

void Contacto::guardarBinario(ofstream &out) const {
    out.write(tipo, sizeof(tipo));
    out.write(valor, sizeof(valor));
}

void Contacto::cargarBinario(ifstream &in) {
    in.read(tipo, sizeof(tipo));
    in.read(valor, sizeof(valor));
}
