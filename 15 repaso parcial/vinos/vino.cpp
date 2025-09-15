#include "vino.h"

Vino::Vino(int nro, char tipo, int cantidad_litros, int anio_produccion)
{
    this->nro = nro;
    this->tipo = tipo;
    this->cantidad_litros = cantidad_litros;
    this->anio_produccion = anio_produccion;
}

void Vino::imprimir(std::ostream &os) const { // Método virtual
    os << "Vino: " << nro << ", Anio: " << anio_produccion;
}

std::ostream &operator<<(std::ostream &os, const Vino &vino) {
    vino.imprimir(os); // Llama al método virtual
    return os;
}



