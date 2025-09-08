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
    AlumnoLibre(int dni, std::string  nombres,   std::string  apellido, int final, int extra);
    std::string  getCondicion() const ;
    friend ostream& operator<<(ostream& os, const AlumnoLibre& dt);
    int getExtra() const;
    int getFinal() const;
};

#endif // ALUMNOLIBRE_H
