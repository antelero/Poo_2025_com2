#ifndef DOBLEMENTEENLAZADA_H
#define DOBLEMENTEENLAZADA_H
#include "nodo.cpp"
#include <iostream>

template <typename T>
class DoblementeEnlazada
{
private:
    Nodo<T>* head;
    Nodo<T>* tail;
    int size;
public:
    DoblementeEnlazada();
    int getSize();
    void addElemento(T value);
    void impPrimeroUltimo();
    void impUltimoPrimero();
};

#endif // DOBLEMENTEENLAZADA_H





