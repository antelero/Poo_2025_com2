#ifndef CLIENTEEXTRA_H
#define CLIENTEEXTRA_H

#include "cliente.h"

class ClienteExtra : public Cliente {
public:
    ClienteExtra(int id, const char* nombre, int litrosConsumidos);
    double calcularMontoAPagar() const override;
    void imprimir(std::ostream &os) const;
};

#endif // CLIENTEEXTRA_H
