#include "catalogo.h"
#include <iostream>

using namespace std;
Catalogo::Catalogo(char * nombre)
{
    this->nombre = nombre;
    this->cantDiscos = 0;
    this->discos = nullptr;
}

void Catalogo::addDisco(Disco nuevoDisco)
{
    Disco * aux = new Disco[this->cantDiscos + 1];

    for (int i = 0; i < cantDiscos; ++i) {
        aux[i] = this->discos[i];
    }

    aux[cantDiscos] = nuevoDisco;

    this->discos = aux;

    cantDiscos++;
}

void Catalogo::mostrarCatalogo()
{
    cout<<"Catalogo  "<< this->nombre<<endl;
    for (int i = 0; i < this->cantDiscos; ++i) {
        this->discos[i].mostrarCanciones();
        cout<<endl;
    }
}
