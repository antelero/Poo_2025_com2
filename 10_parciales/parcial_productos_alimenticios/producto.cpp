#include "producto.h"

Producto::Producto(const std::string &c, const std::string &n)
    : codigo(c), nombre(n) {}

std::string Producto::getCodigo() const { return codigo; }

std::string Producto::getNombre() const { return nombre; }

std::ostream& operator<<(std::ostream& os, const Producto& p) {
    p.imprimir(os);
    return os;
}
