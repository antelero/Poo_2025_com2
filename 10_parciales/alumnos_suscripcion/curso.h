#ifndef CURSO_H
#define CURSO_H

#include <iostream>
#include <cstring>
#include "alumno.h"
// ============================================================
//  Clase Curso — sin STL
//  Arreglo estático de punteros a Alumno.
// ============================================================
class Curso {
private:
    static const int MAX_ALUMNOS = 100;

    char    nombre[100];
    Alumno* alumnos[MAX_ALUMNOS];
    int     cantAlumnos;

public:
    Curso(const char* nombre);

    void agregarAlumno(Alumno* alumno);

    // ── Punto 2: listar aprobados ────────────────────────────
    void listarAprobados() const;

    // ── Punto 4a: alumno con el promedio mas alto ────────────
    void alumnoMasAlto() const;

    // ── Punto 4b: cantidad por tipo (sin map) ────────────────
    // Recorre los tipos conocidos y cuenta manualmente.
    void cantidadPorTipo() const {
        const char* tipos[] = { "Invitado", "Medio", "Premium" };
        int conteo[3] = { 0, 0, 0 };

        for (int i = 0; i < cantAlumnos; i++)
            for (int t = 0; t < 3; t++)
                if (strcmp(alumnos[i]->getTipo(), tipos[t]) == 0)
                    conteo[t]++;

        std::cout << "\n=== Cantidad de alumnos por tipo ===\n";
        for (int t = 0; t < 3; t++)
            std::cout << "  " << tipos[t] << ": " << conteo[t] << "\n";
    }
};

#endif // CURSO_H
