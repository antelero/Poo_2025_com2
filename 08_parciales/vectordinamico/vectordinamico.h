#ifndef VECTORDINAMICO_H
#define VECTORDINAMICO_H


class VectorDinamico
{
private:
    int * vector=nullptr;
    int cant = 0;
public:
    VectorDinamico();
    VectorDinamico(int num);
    int getCant() const;
    int getValor(int indice);
    void add(int num);
    //Métodos requeridos
    VectorDinamico unir( VectorDinamico otro) ;
    VectorDinamico interseccion(VectorDinamico otro);
};

#endif // VECTORDINAMICO_H
