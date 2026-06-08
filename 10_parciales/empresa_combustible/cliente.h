#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <cstring>

class Cliente {
private:
    int id;
    char nombre[250];
    int litrosConsumidos;

public:
    Cliente(int id, const char* nombre, int litrosConsumidos);
    virtual ~Cliente() = default;
    virtual double calcularMontoAPagar() const = 0; // Método virtual puro
    int getId() const;
    const char* getNombre() const;
    int getLitrosConsumidos() const;
    virtual void imprimir(std::ostream& os) const;

    friend std::ostream& operator<<(std::ostream& os, const Cliente& cliente);
};

#endif // CLIENTE_H
