#include "curso.h"
#include <iostream>

// ============================================================
//  main.cpp
//  Los Alumno se crean con new para Curso
// ============================================================

int main() {

    // ── Crear alumnos ─────────────────────────────────────────
    Alumno a1(1, "Ana",   "Gomez",  new SuscripcionInvitado());
    Alumno a2(2, "Bruno", "Lopez",  new SuscripcionMedio());
    Alumno a3(3, "Carla", "Perez",  new SuscripcionPremium());
    Alumno a4(4, "Diego", "Torres", new SuscripcionInvitado());
    Alumno a5(5, "Elena", "Suarez", new SuscripcionMedio());

    // ── Cargar notas ──────────────────────────────────────────
    a1.cargarNota(65.0f);                          // Invitado: 65 > 60  ✔

    a2.cargarNota(72.0f);
    a2.cargarNota(68.0f);
    a2.cargarNota(75.0f);                          // Medio: prom 71.67 > 70  ✔

    a3.cargarNota(85.0f);
    a3.cargarNota(82.0f);
    a3.cargarNota(78.0f);
    a3.cargarNota(90.0f);
    a3.cargarNota(88.0f);                          // Premium: todas>70, prom 84.6  ✔

    a4.cargarNota(55.0f);                          // Invitado: 55 <= 60  ✗

    a5.cargarNota(60.0f);
    a5.cargarNota(65.0f);
    a5.cargarNota(63.0f);                          // Medio: prom 62.67 < 70  ✗

    // ── Armar el curso ────────────────────────────────────────
    Curso curso("Programacion Orientada a Objetos");
    curso.agregarAlumno(&a1);
    curso.agregarAlumno(&a2);
    curso.agregarAlumno(&a3);
    curso.agregarAlumno(&a4);
    curso.agregarAlumno(&a5);

    // ── Punto 2: aprobados ────────────────────────────────────
    curso.listarAprobados();

    // ── Punto 3: upgrade de invitado ─────────────────────────
    std::cout << "\n=== Upgrade: Diego (Invitado -> Medio) ===\n";
    std::cout << "Antes:   " << a4 << "\n";
    a4.upgradeSuscripcion("Medio");
    a4.cargarNota(80.0f);
    a4.cargarNota(85.0f);
    std::cout << "Despues: " << a4 << "\n";

    // Intento invalido
    std::cout << "Intento invalido a2= Medio -> Premium\n";
    a2.upgradeSuscripcion("Premium");   // debe imprimir error

    // ── Punto 4a y 4b ────────────────────────────────────────
    curso.alumnoMasAlto();
    curso.cantidadPorTipo();

    // ── Extra
    std::cout << "\n=== Upgrade: a1:Ana (Invitado -> Premium) ===\n";
    a1.upgradeSuscripcion("Premium");
    std::cout << "Despues: " << a1 << "\n";
    curso.cantidadPorTipo();
    return 0;
}
