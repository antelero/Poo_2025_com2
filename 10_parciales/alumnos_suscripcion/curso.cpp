#include "curso.h"

Curso::Curso(const char *nombre) {
    this->cantAlumnos =0;
    strncpy(this->nombre, nombre, 99);
    this->nombre[99] = '\0';
}

void Curso::agregarAlumno(Alumno *alumno) {
    if (cantAlumnos >= MAX_ALUMNOS) {
        std::cout << "Curso lleno.\n";
        return;
    }
    alumnos[cantAlumnos++] = alumno;
}

void Curso::listarAprobados() const {
    std::cout << "\n=== Alumnos aprobados en \"" << nombre << "\" ===\n";
    bool hayAprobados = false;
    for (int i = 0; i < cantAlumnos; i++) {
        if (alumnos[i]->aprobo()) {
            std::cout << *alumnos[i] << "\n";
            hayAprobados = true;
        }
    }
    if (!hayAprobados)
        std::cout << "(Ningun alumno aprobo el curso.)\n";
}

void Curso::alumnoMasAlto() const {
    if (cantAlumnos == 0) return;

    float maxProm = -1.0f;
    for (int i = 0; i < cantAlumnos; i++) {
        float p = alumnos[i]->getPromedio();
        if (p > maxProm)
            maxProm = p;
    }

    std::cout << "\n=== Alumno(s) con promedio mas alto (" << maxProm << ") ===\n";
    for (int i = 0; i < cantAlumnos; i++)
        if (alumnos[i]->getPromedio() == maxProm)
            std::cout << *alumnos[i] << "\n";
}
