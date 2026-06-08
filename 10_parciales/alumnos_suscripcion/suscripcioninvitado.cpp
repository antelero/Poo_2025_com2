#include "suscripcioninvitado.h"

SuscripcionInvitado::SuscripcionInvitado() : Suscripcion(1) {}

bool SuscripcionInvitado::aprobo() const {
    if (cantNotas < 1) return false;
    return notas[0] > 60.0f;
}

float SuscripcionInvitado::getPromedio() const {
    if (cantNotas < 1) return 0.0f;
    return notas[0];
}

const char *SuscripcionInvitado::getTipo() const {
    return "Invitado";
}
