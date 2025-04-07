/*
1. Realice una función que dado un vector de cstring retorne el mismo cstring en mayúscula.
*/

#include <iostream>

using namespace std;

char *mayuscula(char * cadena);
int cantidad(char * str);

int main()
{
    char * palabra = "hola Mundo";
    cout << mayuscula(palabra)<<endl;
    return 0;
}

char *mayuscula(char * str){
    int cant = cantidad(str);
    cout << cant<<endl;
    char *auxi = new char[cant + 1]; // +1 para el '\0'
    for(int i = 0; i < cant; i++){
        if(str[i] >= 'a' && str[i] <= 'z')
            auxi[i] = str[i] - 32;
        else
            auxi[i] = str[i];
    }
    auxi[cant] = '\0'; // <- cierre de cadena
    return auxi;
}

int cantidad(char * str){
    int i=0;
    while (str[i]!='\0') {
        i++;
    }
    i++;
    return i;
}
