#ifndef CURSO_H
#define CURSO_H

#include <alumno.h>


class Curso
{
private:
    Alumno * alumnos[30];
    char * nombre;
    int cantidad=0;
public:
    Curso(char * nombre);
    void addAlumno(Alumno *alu);


    int getCantidad() const;
    Alumno *getAlumno(int pos);
};

#endif // CURSO_H
