#include "suscripcionpremium.h"


SuscripcionPremium::SuscripcionPremium() : Suscripcion(5) {}

bool SuscripcionPremium::aprobo() const {
    if (cantNotas < cantExamenesRequeridos) return false;

    for (int i = 0; i < cantNotas; i++)
        if (notas[i] <= 70.0f) return false;

    return getPromedio() > 80.0f;
}

float SuscripcionPremium::getPromedio() const {
    if (cantNotas == 0) return 0.0f;
    float suma = 0.0f;
    for (int i = 0; i < cantNotas; i++)
        suma += notas[i];
    return suma / cantNotas;
}

const char *SuscripcionPremium::getTipo() const {
    return "Premium";
}
