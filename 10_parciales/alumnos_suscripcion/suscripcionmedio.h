#ifndef SUSCRIPCIONMEDIO_H
#define SUSCRIPCIONMEDIO_H

#include "suscripcion.h"

// ============================================================
//  SuscripcionMedio — 3 exámenes, promedio > 70
// ============================================================
class SuscripcionMedio : public Suscripcion {
public:
    SuscripcionMedio() : Suscripcion(3) {}

    bool aprobo() const override;

    float getPromedio() const override;

    const char* getTipo() const override;
};

#endif // SUSCRIPCIONMEDIO_H
