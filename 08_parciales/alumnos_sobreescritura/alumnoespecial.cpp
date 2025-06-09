#include "alumnoespecial.h"

int AlumnoEspecial::getCantidad() const
{
    return cantidad;
}

void AlumnoEspecial::addNota(int nota)
{

    if(cantidad==0)
    {
        this->notas[0] = nota;
        cantidad ++;
    }else
    {
        int *aux = new int[this->cantidad+1];
        for(int i = 0; i < this->cantidad; i++){
            aux[i] = this->notas[i];
        }
        aux[this->cantidad] = nota;
        this->notas = aux;
        //delete [] aux;
        this->cantidad += 1;
    }
}

void AlumnoEspecial::delNota(int pos)
{
    if (pos < this->cantidad)
        {
            int *aux = new int[cantidad-1];
            for(int i = 0; i < pos; i++){
                aux[i] = notas[i];
            }
            for(int i = pos+1; i < cantidad; i++){
                aux[i-1] = notas[i];
            }
            this->notas = aux;
            this->cantidad -=1;
        }
}

double AlumnoEspecial::getNota(int pos) const
{
    return  this->notas[pos];
}

double AlumnoEspecial::getPromedio() const
{
    double  prom = 0.0;
    for(int i = 0; i < this->cantidad; i++){
        prom += this->getNota(i);
    }
    prom = prom / this->cantidad;
    return prom;
}

AlumnoEspecial::AlumnoEspecial(int dni, char * nombres, char * apellido): Alumno(dni, nombres,  apellido)
{
}

char *AlumnoEspecial::getCondicion() const
{
    if (this->getPromedio()>60)
        return "Alumno Especial Aprobado";
    else
        return "Alumno Especial NO Aprobado";
}

std::ostream& operator<<(std::ostream& os, const AlumnoEspecial& alu)
{
    os << alu.getNombres()<< ", " << alu.getApellido() << ":  ";
    for(int i=0; i< alu.getCantidad();i++)
        os << "-" << alu.getNota(i);
    return os;
}
