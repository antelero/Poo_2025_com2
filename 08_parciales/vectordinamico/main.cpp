#include <iostream>
#include "vectordinamico.h"

using namespace std;

int main()
{
    cout << "Vamos a Crear un VD" << endl;
    VectorDinamico vd(2);
    vd.add(3);
    vd.add(5);
    //vd.add(4);

    cout << "VD1 " << vd.getCant() << endl;

    VectorDinamico vd2(4);
    vd2.add(4);
    //vd2.add(2);

    cout << "VD2 " << vd2.getCant() << endl;

    VectorDinamico vUnion;
    cout << "Union: " << endl;
    vUnion = vd.unir(vd2);
    cout << "vUnion cantidad " << vUnion.getCant() << endl;
    for (int i = 0; i < vUnion.getCant(); ++i)
        cout << "vUnion " << vUnion.getValor(i) << endl;

    VectorDinamico vInter = vd.interseccion(vd2);
    cout << "Interseccion: " << endl;
    cout << "vInter cantidad " << vInter.getCant() << endl;
    for (int i = 0; i < vInter.getCant(); i++) {
        cout << "vInter " << vInter.getValor(i) << endl;
    }
    cout << endl;
    return 0;
}
