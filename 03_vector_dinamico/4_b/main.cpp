/*
4. Realice una función que dado un vector dinámico de enteros, remueva el elemento que se
encuentra en una posición pasada por parámetro. Si la posición es mayor a la cantidad de
elementos, la función no debe remover ningún elemento.
*/

#include <iostream>
using namespace std;

int * quita(int *vec, int cant, int pos);
void imprimir(int *arr, int cant)
{
    for (int i=0;i<cant;i++)
    {
        cout << arr[i]<<endl;
    }
}
int main(int argc, char *argv[]) {
    int cant = 5;
    int *arr= new int[cant];
    arr[0] = 5;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 6;
    imprimir(arr, cant);
    arr = quita(arr, cant, 2);
    cout<<"Va a quitar el 2"<< endl;
    cant--;
    imprimir(arr, cant);
    cout<<"Va a quitar el 3"<< endl;
    arr = quita(arr, cant, 3);
    cant--;
    imprimir(arr, cant);
    return 0;
}

int * quita(int *vec, int cant, int pos){

    if (pos<cant)
    {
        int *aux = new int[cant - 1];

        for (int i=0;i<cant-1;i++)
        {
            if(i<pos)
                aux[i]=vec[i];
            else aux[i]=vec[i+1];
        }
        delete [] vec;
        return aux;
    }
    else return vec;
}


