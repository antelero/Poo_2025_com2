#include "alumnolibre.h"

int AlumnoLibre::getExtra() const
{
    return extra;
}

int AlumnoLibre::getFinal() const
{
    return final;
}

AlumnoLibre::AlumnoLibre(int dni, std::string  nombres,   std::string  apellido, int final, int extra): Alumno(dni, nombres,  apellido)
{
    this->final = final;
    this->extra = extra;
}

std::string AlumnoLibre::getCondicion() const
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
