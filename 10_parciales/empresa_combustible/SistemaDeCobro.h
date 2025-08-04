#ifndef SISTEMADECOBRO_H
#define SISTEMADECOBRO_H

#include "Cliente.h"
#include <iostream>
#include <fstream>

class SistemaDeCobro {
private:
    Cliente** clientes;
    int size;


public:
    SistemaDeCobro();
    ~SistemaDeCobro();
    void agregarCliente(Cliente* cliente);
    void ordenarClientesPorMonto();
    void imprimirClientes();
    //void guardarEnArchivoBinario(const char* filename);
    int getSize() const;
    Cliente *getCliente(int index) const;
};

#endif // SISTEMADECOBRO_H
