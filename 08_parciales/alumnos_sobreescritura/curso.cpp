#include "curso.h"

int Curso::getCantidad() const
{
    return cantidad;
}

Curso::Curso(char * nombre)
{
    this->nombre = nombre;
}

void Curso::addAlumno(Alumno *alu)
{
    if (this->cantidad<30)
    {
        this->alumnos[cantidad] = alu;
        this->cantidad++;
    }
}


Alumno * Curso::getAlumno(int pos)
{
    return alumnos[pos];
}
