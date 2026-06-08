#ifndef SUSCRIPCIONINVITADO_H
#define SUSCRIPCIONINVITADO_H

#include "suscripcion.h"

// ============================================================
//  SuscripcionInvitado — 1 examen, nota > 60
// ============================================================
class SuscripcionInvitado : public Suscripcion {
public:
    SuscripcionInvitado();

    bool aprobo() const override;

    float getPromedio() const override;

    const char* getTipo() const override;
};

#endif // SUSCRIPCIONINVITADO_H
