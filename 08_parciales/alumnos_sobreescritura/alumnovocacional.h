#ifndef ALUMNOVOCACIONAL_H
#define ALUMNOVOCACIONAL_H

#include "alumno.h"
#include <iostream>
using namespace std;

class AlumnoVocacional : public Alumno
{
private:
    int examen;
public:
    AlumnoVocacional(int dni, char * nombres,   char * apellido, int examen);
    char * getCondicion() const ;
    friend ostream& operator<<(ostream& os, const AlumnoVocacional& dt);
};

#endif // ALUMNOVOCACIONAL_H
