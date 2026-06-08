#include "clientepequeno.h"

ClientePequeno::ClientePequeno(int id, const char* nombre, int litrosConsumidos)
    : Cliente(id, nombre, litrosConsumidos) {}

double ClientePequeno::calcularMontoAPagar() const {
    return this->getLitrosConsumidos() * 220.0;
}

void ClientePequeno::imprimir(std::ostream& os) const {
    Cliente::imprimir(os); // reutiliza la base
    os << "Categoría: Pequeño (tarifa: $220/litro)\n";
}
