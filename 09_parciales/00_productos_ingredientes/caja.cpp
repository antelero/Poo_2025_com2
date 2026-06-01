#include "caja.h"

template<typename T>
Caja<T>::Caja(T v) {
    this->contenido = v;
}

template<typename T>
T Caja<T>::get() const {
    return contenido;
}
