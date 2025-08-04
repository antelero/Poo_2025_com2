#ifndef DOBLEMENTEENLAZADA_H
#define DOBLEMENTEENLAZADA_H
#include "nodo.h"
#include <iostream>

class DoblementeEnlazada
{
private:
    Nodo* head;
    Nodo* tail;
    int size;
public:
    DoblementeEnlazada();
    int getSize();
    void addElemento(int value);
    void impPrimeroUltimo();
    void impUltimoPrimero();
};

#endif // DOBLEMENTEENLAZADA_H





