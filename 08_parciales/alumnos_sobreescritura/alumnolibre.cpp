#include "alumnolibre.h"

AlumnoLibre::AlumnoLibre(int dni, char * nombres,   char * apellido, int final, int extra): Alumno(dni, nombres,  apellido)
{
    this->final = final;
    this->extra = extra;
}

char *AlumnoLibre::getCondicion() const
{
    if (this->final >= 70 & this->extra>=70)
        return "Aprobado Libre";
    else
        return "Reprobado Libre";
}
ostream& operator<<(ostream& os, const AlumnoLibre& dt)
{
    os <<  dt.getNombres()<< ", " << dt.getApellido() << ":  " << dt.final << " - " << dt.extra;
    return os;
}
