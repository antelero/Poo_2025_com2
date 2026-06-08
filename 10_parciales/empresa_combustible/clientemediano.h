#ifndef CLIENTEMEDIANO_H
#define CLIENTEMEDIANO_H

#include "Cliente.h"

class ClienteMediano : public Cliente {
public:
    ClienteMediano(int id, const char* nombre, int litrosConsumidos);
    double calcularMontoAPagar() const override;
    void imprimir(std::ostream &os) const;
};

#endif // CLIENTEMEDIANO_H
