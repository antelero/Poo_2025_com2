#include "vectordinamico.h"


template<typename T>
void VectorDinamico<T>::redimensionar(int nuevaCapacidad) {
    T* nuevosDatos = new T[nuevaCapacidad];
    for (int i = 0; i < cantidad; ++i) {
        nuevosDatos[i] = datos[i];
    }
    delete[] datos;
    datos = nuevosDatos;
    capacidad = nuevaCapacidad;
}

template<typename T>
VectorDinamico<T>::VectorDinamico() : capacidad(10), cantidad(0) {
    datos = new T[capacidad];
}

template<typename T>
VectorDinamico<T>::~VectorDinamico() {
    delete[] datos;
}

template<typename T>
void VectorDinamico<T>::agregar(const T &elemento) {
    if (cantidad == capacidad) {
        redimensionar(capacidad * 2);
    }
    datos[cantidad++] = elemento;
}

template<typename T>
T VectorDinamico<T>::obtener(int indice) const {
    if (indice < 0 || indice >= cantidad) {
        throw std::out_of_range("Índice fuera de rango");
    }
    return datos[indice];
}

template<typename T>
void VectorDinamico<T>::eliminarTodas(const T &elemento) {
    int j = 0;
    for (int i = 0; i < cantidad; ++i) {
        if (!(datos[i] == elemento)) {
            datos[j++] = datos[i];
        }
    }
    cantidad = j;
}

template<typename T>
int VectorDinamico<T>::size() const {
    return cantidad;
}

template<typename T>
const T &VectorDinamico<T>::operator[](int i) const {
    return datos[i];
}

template<typename T>
T &VectorDinamico<T>::operator[](int i) {
    return datos[i];
}
