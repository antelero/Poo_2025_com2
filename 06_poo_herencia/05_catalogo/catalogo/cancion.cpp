#include "cancion.h"

Cancion::Cancion()
{
    this->nombre = "";
    this->duracion = 0;
    this->autor;
}

Cancion::Cancion(char * nombre, double duracion)
{
    this->nombre = "";
    this->duracion = 0;
}

void Cancion::setNombre(char * nombre){
    this->nombre = nombre;
}

char *  Cancion::getNombre(){
    return this->nombre;
}
void Cancion::setDuracion(double duracion){
    this->duracion = duracion;
}

double  Cancion::getDuracion(){
    return this->duracion;
}

void Cancion::setAutor(Autor autor){
    this->autor = autor;
}
Autor Cancion::getAutor(){
    return this->autor;
}
