#include "cadena.h"

Cadena::Cadena(char  * cadena)
{
    this->cadena = cadena;
}

int Cadena::ocurre(char caracter)
{
    int i = 0;
    while(this->cadena[i]!='\0')
    {
        if(this->cadena[i]==caracter)
        {
            return i;
            break;
        }

        i++;
    }
    return -1;
}

int Cadena::Long()
{
    int i = 0;
    while(this->cadena[i]!='\0')
    {
        i++;
    }
    return ++i;
}

char * Cadena::addFinal(char caracter)
{
    int cant = this->Long();
    char * aux = new char[cant+1];
    for(int i=0;i<cant - 1; i++)
    {
        aux[i] = this->cadena[i];
    }
    aux[cant-1] = caracter;
    aux[cant] = '\0';
    return aux;
}

char * Cadena::addInicio(char caracter)
{
    int cant = this->Long();
    char * aux = new char[cant+1];
    aux[0] = caracter;
    for(int i=0;i<cant - 1; i++)
    {
        aux[i+1] = this->cadena[i];
    }
    aux[cant] = '\0';
    return aux;
}

char *Cadena::delOcurrencia(char caracter)
{
    int pos = ocurre(caracter);
    if(pos!=-1)
    {
        int cant = this->Long();
        char * aux = new char[cant-1];
        for(int i=0;i<cant - 1; i++)
        {
            if (i<pos)
               aux[i] = this->cadena[i];
            else  aux[i] = this->cadena[i+1];
        }
        //aux[cant-1] = '\0';

        return aux;
    }

}

char *Cadena::toUpper()
{
    int cant = this->Long();
    char * aux = new char[cant];
    for(int i=0;i<cant - 1; i++)
    {
        if(this->cadena[i]>='a' & this->cadena[i]<='z')
            aux[i] = this->cadena[i]-32;
        else aux[i] = this->cadena[i];
    }
    aux[cant] = '\0';
    return aux;
}

char *Cadena::getCadena()
{
    return this->cadena;
}
