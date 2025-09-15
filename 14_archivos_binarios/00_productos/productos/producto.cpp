#include "producto.h"

Producto::Producto(string n, double p)  {
    nombre= n;
    precio = p;
}

Producto::~Producto() {

}

string Producto::getNombre() const {
    return nombre;
}

double Producto::getPrecio() const {
    return precio;
}

double Producto::calcular(int cantidad) const {
    return precio * cantidad;
}

void Producto::imprimir(ostream& os) const {
    os << "Producto: " << nombre << " | Precio: " << precio;
}

ostream& operator<<(ostream& os, const Producto& p) {
    p.imprimir(os);
    return os;
}
