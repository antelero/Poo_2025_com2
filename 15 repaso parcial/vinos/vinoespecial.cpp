#include "vinoespecial.h"



VinoEspecial::VinoEspecial(int nro, int cantidad_litros, int anio_produccion): Vino(nro, 'E', cantidad_litros, anio_produccion)
{

}

int VinoEspecial::getLtsVenta(int anio) const {
    return (anio - anio_produccion >= 3) ? cantidad_litros : 0;
}

double VinoEspecial::getMntVenta(int anio) const
{
    return getLtsVenta(anio) * 320.0;
}

void VinoEspecial::imprimir(std::ostream &os) const { // Sobreescritura
    Vino::imprimir(os);  // Llamada al método de la clase base
    os << " (Especial)"; // Información específica de la subclase
}

std::ostream &operator<<(std::ostream &os, const VinoEspecial &vino) {
    vino.imprimir(os);
    return os;
}

