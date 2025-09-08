#ifndef CURSO_H
#define CURSO_H

#include <alumno.h>
#include "alumnoespecial.h"
#include "alumnolibre.h"
#include "alumnonormal.h"
#include "alumnovocacional.h"
#include <vector>
#include <algorithm>
#include <fstream>
class Curso
{
private:
    std::vector<Alumno*> alumnos;
    std::string  nombre;
    int cantidad=0;
public:
    Curso(std::string  nombre);
    void addAlumno(Alumno *alu);
    int getCantidad() ;
    Alumno *getAlumno(int pos);
    void ordenar(char orden='A');
    Alumno *buscarNombre(std::string buscado);
    void grabarTxt();

    void grabarTxtObj();
    void leerTxtObj();
    void limpiar();
};

#endif // CURSO_H
