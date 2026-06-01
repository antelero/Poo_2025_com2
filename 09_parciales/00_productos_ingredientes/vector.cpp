#include "vector.h"

template<typename T>
void Vector<T>::redimensionar() {
    capacidad *= 2;
    T* nuevo = new T[capacidad];
    for (int i = 0; i < cantidad; i++)
        nuevo[i] = datos[i];
    delete[] datos;
    datos = nuevo;
}

template<typename T>
Vector<T>::Vector(int capInicial) {
    capacidad = capInicial;
    cantidad = 0;
    datos = new T[capacidad];
}

template<typename T>
Vector<T>::Vector(const Vector<T> &otro)
    : capacidad(otro.capacidad), cantidad(otro.cantidad) {
    datos = new T[capacidad];
    for (int i = 0; i < cantidad; i++)
        datos[i] = otro.datos[i];
}

template<typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &otro) {
    if (this == &otro)
        return *this;
    delete[] datos;
    capacidad = otro.capacidad;
    cantidad  = otro.cantidad;
    datos = new T[capacidad];
    for (int i = 0; i < cantidad; i++)
        datos[i] = otro.datos[i];
    return *this;
}

template<typename T>
Vector<T>::~Vector() {
    delete[] datos;
}

template<typename T>
void Vector<T>::agregar(const T &elemento) {
    if (cantidad == capacidad)
        redimensionar();
    datos[cantidad++] = elemento;
}

template<typename T>
const T &Vector<T>::obtener(int indice) const {
    if (indice < 0 || indice >= cantidad)
        throw "Indice fuera de rango";
    return datos[indice];
}

template<typename T>
void Vector<T>::eliminarOcurrencias(const T &elemento) {
    int nuevaCantidad = 0;
    for (int i = 0; i < cantidad; i++) {
        if (!(datos[i] == elemento))
            datos[nuevaCantidad++] = datos[i];
    }
    cantidad = nuevaCantidad;
}

template<typename T>
int Vector<T>::size() const { return cantidad; }

template<typename T>
bool Vector<T>::estaVacio() const { return cantidad == 0; }
