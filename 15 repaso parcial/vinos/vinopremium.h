#ifndef VINOPREMIUM_H
#define VINOPREMIUM_H

#include "vino.h"

class VinoPremium : public Vino
{
public:
    VinoPremium(int nro, int cantidad_litros, int anio_produccion);

    int getLtsVenta(int anio);
    double getMntVenta(int anio);
    void imprimir(std::ostream &os) const override;
    // sobrecarga del operador << en la subclase
    friend std::ostream &operator<<(std::ostream &os,
                                    const VinoPremium &vino);
};

#endif // VINOPREMIUM_H
