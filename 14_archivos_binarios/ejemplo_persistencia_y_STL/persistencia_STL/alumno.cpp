#include "alumno.h"

int Alumno::getLegajo() const {
    return legajo;
}

const std::string &Alumno::getNombre() const {
    return nombre;
}

float Alumno::getNota() const {
    return nota;
}
