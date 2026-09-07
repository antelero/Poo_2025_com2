#ifndef ALUMNO_H
#define ALUMNO_H

#include <iostream>
#include <string>

class Alumno {
private:
    int legajo;
    std::string nombre;
    float nota;

public:
    //constructor con lista de inicialización de miembros
    Alumno(int legajo, const std::string& nombre, float nota)
        : legajo(legajo),
          nombre(nombre),
          nota(nota) {}

    int getLegajo() const;
    const std::string& getNombre() const;
    float getNota() const;

    friend std::ostream& operator<<(std::ostream& os, const Alumno& a) {
        os << "#" << a.legajo << " " << a.nombre << " - nota: " << a.nota;
        return os;
    }
};

#endif // ALUMNO_H
