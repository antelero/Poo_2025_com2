#ifndef SUSCRIPCIONPREMIUM_H
#define SUSCRIPCIONPREMIUM_H

#include "suscripcion.h"

// ============================================================
//  SuscripcionPremium — 5 exámenes, todas > 70 Y promedio > 80
// ============================================================
class SuscripcionPremium : public Suscripcion {
public:
    SuscripcionPremium();

    bool aprobo() const override;

    float getPromedio() const override;

    const char* getTipo() const override;
};

#endif // SUSCRIPCIONPREMIUM_H
