#include "noperecedero.h"

const string &NoPerecedero::getTipo() const
{
    return tipo;
}

NoPerecedero::NoPerecedero(string n, double p, string t)
    : Producto(n, p) {
    this->tipo = t;
}

double NoPerecedero::calcular(int cantidad) const {
    return Producto::calcular(cantidad);
}

void NoPerecedero::imprimir(ostream& os) const {
    Producto::imprimir(os);
    os << " | NoPerecedero (Tipo: " << tipo << ")";
}
