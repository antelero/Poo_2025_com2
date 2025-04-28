#ifndef CATALOGO_H
#define CATALOGO_H
#include "disco.h"


class Catalogo
{
private:
    char * nombre;
    Disco * discos;
    int cantDiscos = 0;
public:
    Catalogo(char * nombre);
    void addDisco(Disco  nuevoDisco);
    void mostrarCatalogo();
};

#endif // CATALOGO_H
