#include "vinomesa.h"

VinoMesa::VinoMesa(int nro, int cantidad_litros, int anio_produccion): Vino(nro, 'M', cantidad_litros, anio_produccion)
{

}
int VinoMesa::getLtsVenta(int anio) const {
    return (anio - anio_produccion >= 1) ? cantidad_litros : 0;
}


double VinoMesa::getMntVenta(int anio)  const{
        return getLtsVenta(anio) * 120.0;
}

void VinoMesa::imprimir(std::ostream &os) const { // Sobreescritura
    Vino::imprimir(os);  // Llamada al método de la clase base
    os << " (Mesa)"; // Información específica de la subclase
}

std::ostream &operator<<(std::ostream &os, const VinoMesa &vino) {
    vino.imprimir(os);
    return os;
}


