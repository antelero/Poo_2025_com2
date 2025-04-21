#ifndef CADENA_H
#define CADENA_H

/*
3. Realice una clase Cadena que permita representar una cadena cstring. La cadena debe
permitir:
a) Saber cuantos caracteres tiene la cadena
b) Agregar un carácter al final
c) Agregar un carácter al principio
d) Remover la primera ocurrencia de un carácter pasado por parámetro.
e) Retornar una cadena en mayúscula.
*/

class Cadena
{
private:
    char * cadena;
    int ocurre(char caracter);
public:
    Cadena(char  * cadena);
    int Long();
    char * addFinal(char caracter);
    char * addInicio(char caracter);
    char * delOcurrencia(char caracter);
    char * toUpper();

    char * getCadena();
};

#endif // CADENA_H
