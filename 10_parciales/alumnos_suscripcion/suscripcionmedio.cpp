#include "suscripcionmedio.h"

bool SuscripcionMedio::aprobo() const {
    if (cantNotas < cantExamenesRequeridos) return false;
    return getPromedio() > 70.0f;
}

float SuscripcionMedio::getPromedio() const {
    if (cantNotas == 0) return 0.0f;
    float suma = 0.0f;
    for (int i = 0; i < cantNotas; i++)
        suma += notas[i];
    return suma / cantNotas;
}

const char *SuscripcionMedio::getTipo() const {
    return "Medio";
}
