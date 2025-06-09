#include "alumnovocacional.h"

AlumnoVocacional::AlumnoVocacional(int dni, char * nombres, char * apellido, int examen): Alumno(dni, nombres,  apellido)
{
    this->examen = examen;
}
char *AlumnoVocacional::getCondicion() const
{
    if (this->examen>=70)
        return "Aprobado Vocacional";
    else
        return "Reprobado Vocacional";
}

ostream& operator<<(ostream& os, const AlumnoVocacional& dt)
{
    os << dt.getNombres()<< ", " << dt.getApellido() << ":  " << dt.examen ;
    return os;
}
