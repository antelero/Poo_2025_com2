#include "bicicleta.h"


Bicicleta::Bicicleta(int n, const char* d) : Item(n, d) {
    this->numero = n;
    strncpy(descripcion, d, 200);
    descripcion[199] = '\0';
}

void Bicicleta::agregarParte(Parte *np)
{
    partes.push_back(np);
}

double Bicicleta::getPrecio() const
{
    double total = 0;
    for (Parte* p : partes)
        total += p->getPrecio();
    return total;
}

int Bicicleta::getNumero() const
{
    return numero;
}

const char *Bicicleta::getDescripcion() const
{
    return descripcion;
}

const std::vector<Parte*> &Bicicleta::getPartes() const
{
    return partes;
}
