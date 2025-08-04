#include "cliente.h"

Cliente::Cliente(int id, const char* nombre, int litrosConsumidos) {
    this->id = id;
    this->litrosConsumidos = litrosConsumidos;
    strncpy(this->nombre, nombre, 250);
    this->nombre[249] = '\0'; // Asegurarse de que el nombre esté terminado en '\0'
}

int Cliente::getId() const {
    return id;
}

const char* Cliente::getNombre() const {
    return nombre;
}

int Cliente::getLitrosConsumidos() const {
    return litrosConsumidos;
}

void Cliente::imprimir(std::ostream& os) const {
    os << "ID: " << id << "\n";
    os << "Nombre: " << nombre << "\n";
    os << "Litros Consumidos: " << litrosConsumidos << "\n";
}

std::ostream& operator<<(std::ostream& os, const Cliente& cliente) {
    cliente.imprimir(os);
    os << "Monto a Pagar: $" << cliente.calcularMontoAPagar() << "\n";
    return os;
}
