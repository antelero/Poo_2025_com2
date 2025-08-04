#include "clienteextra.h"

ClienteExtra::ClienteExtra(int id, const char* nombre, int litrosConsumidos)
    : Cliente(id, nombre, litrosConsumidos) {

}

double ClienteExtra::calcularMontoAPagar() const {
    return litrosConsumidos * 150.0 + 15000.0;
}

