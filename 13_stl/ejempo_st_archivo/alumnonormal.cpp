#include "alumnonormal.h"

AlumnoNormal::AlumnoNormal(int dni, std::string  nombres,   std::string  apellido, int p1, int p2, int p3, int final): Alumno(dni, nombres,  apellido)
{
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
    this->final = final;
}

std::string AlumnoNormal::getCondicion() const
{
    int prom = (this->p1+this->p2+this->p3)/3;
    if(prom > 60 & this->final>60)
        return "Aprobado Normal";
    else
        return "Reprobado Normal";
}
ostream& operator<<(ostream& os, const AlumnoNormal& dt)
{
    os <<  dt.getNombres()<< ", " << dt.getApellido() << ":  " << dt.final << " - " << dt.p1<< " - " << dt.p2<< " - " << dt.p3;
    return os;
}
