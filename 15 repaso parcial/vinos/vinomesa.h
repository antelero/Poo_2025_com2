#ifndef VINOMESA_H
#define VINOMESA_H

#include "vino.h"

class VinoMesa : public Vino
{
public:
    VinoMesa(int nro, int cantidad_litros, int anio_produccion);

    int getLtsVenta(int anio);
    double getMntVenta(int anio);
    void imprimir(std::ostream &os) const override;
    // sobrecarga del operador << en la subclase
    friend std::ostream &operator<<(std::ostream &os,
                                    const VinoMesa &vino);
};

#endif // VINOMESA_H
