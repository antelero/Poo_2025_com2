#include "persona.h"
#include <cstring>

Persona::Persona(char * nombre, char * telefono){
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);

    this->telefono = new char[strlen(telefono) + 1];
    strcpy(this->telefono, telefono);
}

char * Persona::getNombre(){
    return this->nombre;
}

char * Persona::getTelefono(){
    return this->telefono;
}

std::ostream& operator<<(std::ostream& out, const Persona& a){
    out << a.nombre << " " << a.telefono << "  ";
    return out;
}
