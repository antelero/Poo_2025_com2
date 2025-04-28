#include "disco.h"

Disco::Disco()
{
    cant = 0;
    canciones = nullptr;

}
void Disco::setNombre(char * nombre){
    this->nombre = nombre;
}

char *  Disco::getNombre(){
    return this->nombre;
}

void Disco::addCancion(Cancion cancion)
{
    Cancion* aux = new Cancion[cant + 1];
        for (int i = 0; i < cant; ++i)
            aux[i] = canciones[i];  // usa el operador de asignación

        aux[cant] = cancion;  // copia del objeto

        delete[] canciones;
        canciones = aux;
        cant++;
}



void Disco::mostrarCanciones()
{
    std::cout<<"Disco => "<<this->nombre <<" <="
                                           " "<< std::endl;
    for (int i = 0; i < this->cant; ++i) {
        std::cout<<i+1<<" - "<<this->canciones[i].getNombre() << " -> Autor: " << this->canciones[i].getAutor().getNombre()
                 << " -> Duracion: " << this->canciones[i].getDuracion()
                 << "' "
        << std::endl;
    }
}
