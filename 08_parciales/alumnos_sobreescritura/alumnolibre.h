#ifndef ALUMNOLIBRE_H
#define ALUMNOLIBRE_H
/*
Alumnos libres: Solo realizan un examen final que se prueba con 70% y además deben
aprobar un ejercicio más.
*/
#include "alumno.h"
#include <iostream>
using namespace std;


class AlumnoLibre : public Alumno
{
private:
    int final;
    int extra;
public:
    AlumnoLibre(int dni, char * nombres,   char * apellido, int final, int extra);
    char * getCondicion() const ;
    friend ostream& operator<<(ostream& os, const AlumnoLibre& dt);
};

#endif // ALUMNOLIBRE_H
