#include "nodo.h"

template <class T>
Nodo<T>::Nodo()
{

}

template <class T>
Nodo<T>::Nodo(T value) {
    this->dato = value;
    this->next = nullptr;
    this->prev =nullptr;
}
