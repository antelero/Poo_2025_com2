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
    AlumnoVocacional(int dni, std::string  nombres,   std::string  apellido, int examen);
    std::string  getCondicion() const ;
    friend ostream& operator<<(ostream& os, const AlumnoVocacional& dt);
    int getExamen() const;
};

#endif // ALUMNOVOCACIONAL_H
