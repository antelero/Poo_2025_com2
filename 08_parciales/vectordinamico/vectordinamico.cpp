#include "vectordinamico.h"

VectorDinamico::VectorDinamico()
{
}

VectorDinamico::VectorDinamico(int num)
{
    cant = 1;
    vector = new int[1];
    vector[0] = num;
}

void VectorDinamico::add(int num)
{
    int *aux = new int[cant+1];
    for(int i = 0; i < cant; i++){
        aux[i] = this->vector[i];
    }
    aux[cant] = num;
    delete [] this->vector;
    cant++;
    this->vector = aux;
}

int VectorDinamico::getCant() const
{
    return cant;
}

int VectorDinamico::getValor(int indice) {
    if (indice >= 0 && indice < cant)
        return vector[indice];
    else
        return 0;
}

// Unión de dos vectores
VectorDinamico VectorDinamico::unir(VectorDinamico otro) {
    VectorDinamico resultado;
    for (int i = 0; i < this->cant; ++i)
        resultado.add(vector[i]);
    for (int i = 0; i < otro.getCant(); ++i)
        resultado.add(otro.getValor(i));
    return resultado;
}

VectorDinamico VectorDinamico::interseccion(VectorDinamico otro) {
    VectorDinamico resultado;
    for (int i = 0; i < this->cant; i++) {
        for (int j = 0; j < otro.getCant(); j++) {
            if (this->vector[i] == otro.getValor(j)) {
                // Verificar que no esté repetido en resultado
                bool yaEsta = false;
                for (int k = 0; k < resultado.getCant(); k++) {
                    if (resultado.getValor(k) == this->vector[i]) {
                        yaEsta = true;
                        break;
                    }
                }
                if (!yaEsta) {
                    resultado.add(this->vector[i]);
                }
            }
        }
    }
    return resultado;
}
