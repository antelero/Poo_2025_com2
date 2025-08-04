#include "producto.h"

Producto::Producto(const std::string &c, const std::string &n) {
     this->codigo = c;
     this->nombre = n;
}

std::string Producto::getCodigo() const { return codigo; }

std::string Producto::getNombre() const { return nombre; }

std::ostream& operator<<(std::ostream& os, const Producto& p) {
    p.imprimir(os);
    return os;
}
bool Producto::operator==(const Producto& otro) const {
    return this->codigo == otro.codigo;  //  cualquier campo que represente igualdad
}
