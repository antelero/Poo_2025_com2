#include "producto.h"

Producto::Producto()  {
     codigo = 0;
     nombre[0] = '\0';
}

Producto::Producto(int cod, const char *nom) {
    codigo = cod;
    strncpy(nombre, nom, 63);
    nombre[63] = '\0';
}

int Producto::getCodigo() const { return codigo; }

const char *Producto::getNombre() const { return nombre; }

void Producto::imprimirDetalle(ostream &os) const { (void)os; }

ostream& operator<<(ostream& os, const Producto& p) {
    os << "[" << p.codigo << "] " << p.nombre << "\n";
    p.imprimirDetalle(os);
    os << "  Ingredientes: ";
    Vector<Ingrediente> ings = p.getIngredientes();
    if (ings.estaVacio()) {
        os << "(ninguno)";
    } else {
        for (int i = 0; i < ings.size(); i++) {
            if (i > 0) os << ", ";
            os << ings.obtener(i);
        }
    }
    os << "\n";
    return os;
}
