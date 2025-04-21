#include <iostream>
#include "cadena.h"
using namespace std;

int main()
{
    Cadena c("Hola");
    cout << "Cantidad de caracteres: " << c.Long() << endl;
    char x = 'a';
    c = c.addInicio(x);
    cout << "Agrega al Inicio  "<< x <<": " <<  c.getCadena() << endl;
    x = 'B';
    c = c.addFinal(x);
    cout << "Agrega al Fin  "<< x <<": " <<  c.getCadena() << endl;
    c = c.toUpper();
    cout << "Convierte a Mayuscula " <<  c.getCadena() << endl;
    x = 'A';
    c = c.delOcurrencia(x);
    cout << "Ocurrencia del Caracter "<< x <<": " <<  c.getCadena() << endl;
    return 0;
}
