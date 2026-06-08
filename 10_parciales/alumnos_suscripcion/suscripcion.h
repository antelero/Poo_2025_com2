#ifndef SUSCRIPCION_H
#define SUSCRIPCION_H

#include <iostream>

// ============================================================
//  Clase abstracta Suscripcion — sin STL
//  Arreglo estático de notas con tamaño máximo 5 (Premium).
// ============================================================
class Suscripcion {
protected:
    float        notas[5];
    int          cantNotas;
    int          cantExamenesRequeridos;

public:
    Suscripcion(int cantExamenes);
    virtual ~Suscripcion() = default;

    virtual bool aprobo()      const = 0;
    virtual float getPromedio() const = 0;
    virtual const char* getTipo() const = 0;

    void cargarNota(float nota);
    int getCantNotas()              const;
    int getCantExamenesRequeridos() const;

    void transferirNotasA(Suscripcion& destino) const;
};
#endif // SUSCRIPCION_H
