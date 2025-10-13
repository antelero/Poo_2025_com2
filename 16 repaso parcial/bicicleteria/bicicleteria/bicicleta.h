#ifndef BICICLETA_H
#define BICICLETA_H
#include <cstring>
#include <vector>
#include "item.h"
#include "parte.h"


class Bicicleta: public Item{
private:
    int numero;
    char descripcion[200];
    std::vector<Parte*> partes;
public:
    Bicicleta(int n, const char* d);
    void agregarParte(Parte* np);
    double getPrecio() const;
    int getNumero() const;
    const char* getDescripcion() const;
    const std::vector<Parte*>& getPartes() const;
};

#endif // BICICLETA_H
