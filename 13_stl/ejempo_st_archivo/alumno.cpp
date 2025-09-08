#include "alumno.h"
#include <ostream>

std::string Alumno::getNombres() const
{
    return nombres;
}

std::string Alumno::getApellido() const
{
    return apellido;
}

std::string Alumno::getEmail()
{
    std::string dominio = "@uader.edu.ar";
    std::string tempo;
    // primera letra del nombre
    tempo.push_back(this->getNombres()[0]);
    // apellido
    tempo += this->getApellido();
    // dominio
    tempo += dominio;
    return tempo;
}

Alumno::Alumno(int dni, std::string  nombres,   std::string  apellido)
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
