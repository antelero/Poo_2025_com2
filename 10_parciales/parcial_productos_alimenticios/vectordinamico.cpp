#include "vectordinamico.h"

template<typename T>
VectorDinamico<T>::VectorDinamico() {
    this->cantidad = 0;
    this->datos = new T[1];
}

template<typename T>
VectorDinamico<T>::~VectorDinamico() {
    delete[] this->datos;
}

template<typename T>
void VectorDinamico<T>::agregar(const T &elemento) {
    T* nuevosDatos = new T[cantidad + 1];
    for (int i = 0; i < cantidad; ++i) {
        nuevosDatos[i] = datos[i];
    }
    delete[] this->datos;
    this->datos = nuevosDatos;
    this->datos[this->cantidad++] = elemento;
}

template<typename T>
T VectorDinamico<T>::obtener(int indice) const {
    if (indice < 0 || indice >= this->cantidad) {
        throw std::out_of_range("Indice fuera de rango");
    }
    return this->datos[indice];
}

template<typename T>
void VectorDinamico<T>::eliminarTodas(const T &elemento) {
    int j = 0;
    for (int i = 0; i < this->cantidad; ++i) {
        if (!(this->datos[i] == elemento)) {
            this->datos[j++] = this->datos[i];
        }
    }
    this->cantidad = j;
}

template<typename T>
int VectorDinamico<T>::size() const {
    return this->cantidad;
}

template<typename T>
const T &VectorDinamico<T>::operator[](int i) const {
    return this->datos[i];
}

template<typename T>
T &VectorDinamico<T>::operator[](int i) {
    return this->datos[i];
}
