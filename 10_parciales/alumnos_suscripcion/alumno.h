#ifndef ALUMNO_H
#define ALUMNO_H

#include <iostream>
#include <cstring>
#include "suscripcion.h"
#include "suscripcioninvitado.h"
#include "suscripcionmedio.h"
#include "suscripcionpremium.h"

// ============================================================
//  Clase Alumno
//  char[] para nombre/apellido, puntero crudo para suscripcion.
// ============================================================
class Alumno {
private:
    int  codigo;
    char nombre[50];
    char apellido[50];

    Suscripcion* suscripcion;   // puntero a la suscripcion actual

public:
    Alumno(int codigo, const char* nombre, const char* apellido,
           Suscripcion* suscripcion);

    ~Alumno();

    // ── Getters ──────────────────────────────────────────────
    int         getCodigo()   const;
    const char* getNombre()   const;
    const char* getApellido() const;
    const char* getTipo()     const;

    // ── Delegación al estado actual ──────────────────────────
    bool  aprobo()      const;
    float getPromedio() const;

    void cargarNota(float nota);

    // ── Upgrade de suscripción (Punto 3) ─────────────────────
    // Solo Invitado puede hacer upgrade.
    void upgradeSuscripcion(const char* nuevoTipo);

    // ── Sobrecarga operator<< ─────────────────────────────────
    friend std::ostream& operator<<(std::ostream& os, const Alumno& a) {
        os << "[" << a.codigo << "] "
           << a.apellido << ", " << a.nombre
           << " | Tipo: "      << a.suscripcion->getTipo()
           << " | Promedio: "  << a.getPromedio()
           << " | Aprobado: "  << (a.aprobo() ? "SI" : "NO");
        return os;
    }
};

#endif // ALUMNO_H
