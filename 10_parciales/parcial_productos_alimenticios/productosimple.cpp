#include "productosimple.h"


ProductoSimple::ProductoSimple(const std::string &c, const std::string &n)
    : Producto(c, n) {}

void ProductoSimple::agregarIngrediente(const std::string &ing) {
    ingredientes.agregar(ing);
}

VectorDinamico<std::string> ProductoSimple::getIngredientes() const {
    return ingredientes;
}

void ProductoSimple::imprimir(std::ostream &os) const {
    os << "Producto simple: " << nombre << " (codigo: " << codigo << ")\n";
    os << "Ingredientes: ";
    for (int i = 0; i < ingredientes.size(); ++i) {
        os << ingredientes[i];
        if (i < ingredientes.size() - 1) os << ", ";
    }
    os << "\n";
}

bool ProductoSimple::esCompuesto() const { return false; }
