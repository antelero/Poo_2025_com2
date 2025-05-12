#include <iostream>
#include "auto.h"
using namespace std;

int main()
{
    Rueda r1(16), r2(16), r3(16), r4(16);
       Rueda* arregloRuedas[4] = { &r1, &r2, &r3, &r4 };
       Auto miAuto(120, arregloRuedas);
       miAuto.arrancar();
     cout << "Hello World!" << endl;
    return 0;
}
