#include "item.h"

Item::Item(int n = 0, const char* d = "") {
    numero = n;
    strncpy(descripcion, d, 199);
    descripcion[199] = '\0';
}

const char* Item::getDescripcion() const {
    return descripcion;
}
int Item::getNumero() const {
    return numero;
}


