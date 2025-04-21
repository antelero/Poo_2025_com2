#include <iostream>
#include "vectordinamico.h"
using namespace std;

void imprimir(VectorDinamico arr)
{
    for (int i = 0; i < arr.getCant(); i++)
        cout << "[" << i << "] = " << arr.get(i) << "  ";
}

int main()
{
    VectorDinamico vec;
    vec.add(5);
    vec.add(3);
    vec.add(2);
    vec.add(4);
    imprimir(vec);
    cout << endl << "Cant " << vec.getCant() << endl;
    cout << endl << "Borrar la posicion 1: "<< endl;
    vec.remove(1);

    cout << "Cant " << vec.getCant() << endl;
    imprimir(vec);
    cout << endl;
    return 0;
}
