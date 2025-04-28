#ifndef CANCION_H
#define CANCION_H

#include <autor.h>

class Cancion
{
protected:
    char *nombre = "";
    double duracion=0;
    Autor autor;
public:
    Cancion();
    Cancion(char * nombre, double duracion);
    void setNombre(char *nombre);
    void setAutor(Autor autor);
    Autor getAutor();
    void setDuracion(double duracion);
    char *getNombre();
    double getDuracion();
};

#endif // CANCION_H
