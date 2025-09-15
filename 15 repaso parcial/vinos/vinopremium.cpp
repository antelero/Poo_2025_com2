#include "vinopremium.h"


VinoPremium::VinoPremium(int nro, int cantidad_litros, int anio_produccion):Vino(nro, 'P', cantidad_litros, anio_produccion)
{

}

int VinoPremium::getLtsVenta(int anio)
{
    return (anio - anio_produccion >= 2) ? cantidad_litros : 0;
}

double VinoPremium::getMntVenta(int anio)
{
    return getLtsVenta(anio) * 200.0;

}

void VinoPremium::imprimir(std::ostream &os) const { // Sobreescritura
    Vino::imprimir(os);  // Llamada al método de la clase base
    os << " (Premium)"; // Información específica de la subclase
}

std::ostream &operator<<(std::ostream &os, const VinoPremium &vino) {
    vino.imprimir(os);
    return os;
}
