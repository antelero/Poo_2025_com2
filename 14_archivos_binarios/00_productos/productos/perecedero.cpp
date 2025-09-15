#include "perecedero.h"

int Perecedero::getDias() const
{
    return dias_a_caducar;
}

Perecedero::Perecedero(string n, double p, int d)
    : Producto(n, p) {
    this->dias_a_caducar =d;
}

double Perecedero::calcular(int cantidad) const {
    double subtotal = Producto::calcular(cantidad);
    if (dias_a_caducar == 1)
        subtotal /= 4;
    else if (dias_a_caducar == 2)
        subtotal /= 3;
    else if (dias_a_caducar == 3)
        subtotal /= 2;
    return subtotal;
}

void Perecedero::imprimir(ostream& os) const {
    Producto::imprimir(os);
    os << " | Perecedero (caduca en " << dias_a_caducar << " dias)";
}
