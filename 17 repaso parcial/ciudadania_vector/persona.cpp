#include "persona.h"

Persona::Persona(const char* dni, const char* nombre, const char* apellido, const char* nacionalidad)
{
    strncpy(this->dni, dni, sizeof(this->dni));
    strncpy(this->nombre, nombre, sizeof(this->nombre));
    strncpy(this->apellido, apellido, sizeof(this->apellido));
    strncpy(this->nacionalidad, nacionalidad, sizeof(this->nacionalidad));
    //Al crearse se crea sin antesesores
    this->padre = nullptr;
    this->madre = nullptr;
}


void Persona::setPadre(Persona* p) {
    this->padre = p;
}
void Persona::setMadre(Persona* m) {
    this->madre = m;
}

Persona* Persona::getPadre() const {
    return this->padre;
}
Persona* Persona::getMadre() const {
    return this->madre;
}
const char* Persona::getDNI() const {
    return this->dni;
}
const char* Persona::getNombre() const {
    return this->nombre;
}
const char* Persona::getApellido() const {
    return this->apellido;
}
const char* Persona::getNacionalidad() const {
    return this->nacionalidad;
}
