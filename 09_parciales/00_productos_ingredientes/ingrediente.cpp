#include "ingrediente.h"


Ingrediente::Ingrediente() {
    nombre[0] = '\0';
}

Ingrediente::Ingrediente(const char *nom) {
    strncpy(nombre, nom, 63);
    nombre[63] = '\0';
}

const char *Ingrediente::getNombre() const {
    return nombre;
}

bool Ingrediente::operator==(const Ingrediente &otro) const {
    return strcmp(nombre, otro.nombre) == 0;
}


