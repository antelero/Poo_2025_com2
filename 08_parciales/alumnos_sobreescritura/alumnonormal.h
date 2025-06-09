#ifndef ALUMNONORMAL_H
#define ALUMNONORMAL_H

#include "alumno.h"
#include <iostream>
using namespace std;

/*
Alumnos normales: tienen 3 parciales y un examen final. Para aprobar el curso deben tener
un promedio de 60% en los parciales y más de 60 en el examen final.
*/
class AlumnoNormal : public Alumno
{
public:
    int p1,p2,p3,final;

    AlumnoNormal(int dni, char * nombres,   char * apellido, int p1, int p2, int p3, int final);
    char * getCondicion() const ;
    friend ostream& operator<<(ostream& os, const AlumnoNormal& dt);
};

#endif // ALUMNONORMAL_H
