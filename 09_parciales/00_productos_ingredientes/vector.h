#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cstring>

using namespace std;

// ============================================================
// PUNTO 1 — Vector Dinámico Template
// ============================================================

template <typename T>
class Vector
{

private:
    T*     datos;
    int    capacidad;
    int    cantidad;

    void redimensionar();

public:
    Vector(int capInicial = 4);

    // Constructor de copia
    Vector(const Vector<T>& otro);

    // Operador asignación
    Vector<T>& operator=(const Vector<T>& otro);

    ~Vector();

    // 1) Agregar un elemento
    void agregar(const T& elemento);

    // 2) Recuperar un elemento por índice
    const T& obtener(int indice) const;

    // 3) Eliminar todas las ocurrencias de un objeto
    //    Requiere que T tenga operator==
    void eliminarOcurrencias(const T& elemento);

    int size() const;
    bool estaVacio() const;
};


#endif // VECTOR_H
