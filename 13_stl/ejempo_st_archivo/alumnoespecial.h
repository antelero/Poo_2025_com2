#ifndef ALUMNOESPECIAL_H
#define ALUMNOESPECIAL_H

#include <iostream>

#include "alumno.h"
/*
    agregar notas,
    mostrar todas las notas,
    eliminar una nota en particular,
    calcular promedio
*/

class AlumnoEspecial : public Alumno
{
private:
    int * notas = new int;
    int cantidad = 0;
public:
    AlumnoEspecial(int dni, std::string  nombres, std::string  apellido);
    std::string  getCondicion() const ;
    int getCantidad() const;
    void addNota(int nota);
    void delNota(int pos);
    double getNota(int pos) const;
    double getPromedio() const;
    friend std::ostream& operator<<(std::ostream& os, const AlumnoEspecial& dt);
};

#endif // ALUMNOESPECIAL_H
