#include "gestorformas.h"
#include "iostream"

int Gestorformas::getCantidad()
{
    return this->cantidad;
}

Forma *Gestorformas::getObjeto(int pos)
{
    return formas[pos];
}

void Gestorformas::addForma(Forma *form)
{
    Forma ** aux = new Forma*[this->cantidad + 1];
    for (int i = 0; i < cantidad; i++) {
         aux[i] = this->formas[i];
    }
    aux[cantidad] = form;
    delete [] this->formas;
    this->formas = aux;
    this->cantidad++;
}


Gestorformas::Gestorformas()
{

}
