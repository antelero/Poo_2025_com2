#ifndef VINOESPECIAL_H
#define VINOESPECIAL_H

#include "vino.h"

class VinoEspecial : public Vino
{
public:
    VinoEspecial(int nro, int cantidad_litros, int anio_produccion);


    double getMntVenta(int anio) const;
    // Sobrecargar el operador<<
    void imprimir(std::ostream &os) const override;
    // sobrecarga del operador << en la subclase
    friend std::ostream &operator<<(std::ostream &os,
                                    const VinoEspecial &vino);
    int getLtsVenta(int anio) const;
};

#endif // VINOESPECIAL_H
