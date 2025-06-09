#include "alumno.h"
#include <ostream>

char *Alumno::getNombres() const
{
    return nombres;
}

char *Alumno::getApellido() const
{
    return apellido;
}

char *Alumno::getEmail()
{
    const char * dominio = "@uader.edu.ar";
    char * tempo = new char[1 + strlen(this->getApellido()) + strlen(dominio) + 1];
    char x = this->getNombres()[0];
    strcpy(tempo, &x);
    strcat(tempo, this->getApellido());
    strcat(tempo, dominio);
    return tempo;
}

Alumno::Alumno(int dni, char * nombres,   char * apellido)
{
    this->dni = dni;
    this->nombres = nombres;
    this->apellido = apellido;

}

std::ostream& operator<<(std::ostream& os, const Alumno& a) {
    os << "Apellido: " << a.getApellido()
       << ", Nombre: " << a.getNombres()
       << " => Condicion: " << a.getCondicion();
    return os;
}
