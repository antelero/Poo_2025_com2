#include <iostream>
#include "fraccion.h"

using namespace std;

int main()
{
    Fraccion f = Fraccion(2, 3);
    double d = f.mostrarFraccion();
    cout << d << endl;
    cout << f.toString() << " suma " << Fraccion(1,4).toString() << " = " << f.suma(Fraccion(1,4)).toString() << endl;
    cout << f.toString() << " resta " << Fraccion(1,4).toString() << " = " << f.resta(Fraccion(1,4)).toString() << endl;
    cout << f.toString() << " multiplicamos " << Fraccion(1,4).toString() << " = " << f.multiplicar(Fraccion(1,4)).toString() << endl;
    return 0;
}

