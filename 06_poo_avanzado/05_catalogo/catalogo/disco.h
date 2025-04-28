#ifndef DISCO_H
#define DISCO_H
#include <cancion.h>
#include <iostream>
class Disco
{
private:
    char * nombre;
    Cancion * canciones;  // arreglo dinámico de objetos Cancion
    int cant = 0;
public:
    Disco();
    void setNombre(char *nombre);
    char * getNombre();
    void addCancion(Cancion cancion);
    Cancion * getCancion();

    void mostrarCanciones();
};

#endif // DISCO_H
