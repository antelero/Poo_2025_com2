#include "autor.h"

Autor::Autor()
{

}
void Autor::setNombre(char * nombre){
    this->nombre = nombre;
}

char *  Autor::getNombre(){
    return this->nombre;
}
