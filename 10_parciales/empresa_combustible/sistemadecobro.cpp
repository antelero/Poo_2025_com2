#include "sistemadecobro.h"

SistemaDeCobro::SistemaDeCobro()  {
    this->size = 0;
    clientes = new Cliente*[1];
}

SistemaDeCobro::~SistemaDeCobro() {
    for (int i = 0; i < size; ++i) {
        delete clientes[i];
    }
    delete[] clientes;
}

int SistemaDeCobro::getSize() const
{
    return size;
}

void SistemaDeCobro::agregarCliente(Cliente* cliente) {
    Cliente** newClientes = new Cliente*[size+1];
    for (int i = 0; i < size; ++i) {
        newClientes[i] = clientes[i];
    }
    delete[] clientes;
    clientes = newClientes;
    clientes[size++] = cliente;
}

void SistemaDeCobro::ordenarClientesPorMonto() {
    // Implementación de ordenamiento por burbuja
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1 - i; ++j) {
            if (clientes[j]->calcularMontoAPagar() < clientes[j + 1]->calcularMontoAPagar()) {
                Cliente* temp = clientes[j];
                clientes[j] = clientes[j + 1];
                clientes[j + 1] = temp;
            }
        }
    }
}

void SistemaDeCobro::imprimirClientes() {
    ordenarClientesPorMonto();
    for (int i = 0; i < size; ++i) {
        std::cout << *clientes[i] << "\n";
    }
}

/*
void SistemaDeCobro::guardarEnArchivoBinario(const char* filename) {
    std::ofstream file(filename, std::ios::binary);
    for (int i = 0; i < size; ++i) {
        file.write(reinterpret_cast<char*>(clientes[i]), sizeof(*clientes[i]));
    }
    file.close();
}
*/
Cliente* SistemaDeCobro::getCliente(int index) const {
        if (index < 0 || index >= this->size) return nullptr;
        return clientes[index];
    }
