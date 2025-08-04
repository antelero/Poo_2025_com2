#ifndef VECTORDINAMICO_H
#define VECTORDINAMICO_H

#include <iostream>

template <typename T>
class VectorDinamico {
private:
    T* datos;
    int cantidad;

public:
    VectorDinamico();
    ~VectorDinamico();

    void agregar(const T& elemento);
    T obtener(int indice) const;
    void eliminarTodas(const T& elemento);
    int size() const;
    T& operator[](int i);
    const T& operator[](int i) const;
};

#endif
