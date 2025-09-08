#include "alumnovocacional.h"

int AlumnoVocacional::getExamen() const
{
    return examen;
}

AlumnoVocacional::AlumnoVocacional(int dni, std::string  nombres, std::string  apellido, int examen): Alumno(dni, nombres,  apellido)
{
    this->examen = examen;
}
std::string AlumnoVocacional::getCondicion() const
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
