#include "nodo.h"

Nodo::Nodo()
{

}

Nodo::Nodo(int value) {
    this->dato = value;
    this->next = nullptr;
    this->prev =nullptr;
}
