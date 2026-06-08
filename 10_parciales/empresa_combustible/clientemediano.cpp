#include "clientemediano.h"

ClienteMediano::ClienteMediano(int id, const char* nombre, int litrosConsumidos)
    : Cliente(id, nombre, litrosConsumidos) {}

double ClienteMediano::calcularMontoAPagar() const {
    return this->getLitrosConsumidos() * 200.0;
}

void ClienteMediano::imprimir(std::ostream& os) const {
    Cliente::imprimir(os); // reutiliza la base
    os << "Categoría: Mediano (tarifa: $200/litro)\n";
}
