#include "clienteextra.h"

ClienteExtra::ClienteExtra(int id, const char* nombre, int litrosConsumidos)
    : Cliente(id, nombre, litrosConsumidos) {

}

double ClienteExtra::calcularMontoAPagar() const {
    return this->getLitrosConsumidos() * 150.0 + 15000.0;
}

void ClienteExtra::imprimir(std::ostream& os) const {
    Cliente::imprimir(os); // reutiliza la base
    os << "Categoría: Mediano (tarifa: $150/litro + 15000)\n";
}


