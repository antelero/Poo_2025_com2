#include "productocompuesto.h"


ProductoCompuesto::ProductoCompuesto(const std::string &c, const std::string &n)
    : Producto(c, n) {}

void ProductoCompuesto::agregarProducto(Producto *p) {
    subproductos.agregar(p);
}

VectorDinamico<std::string> ProductoCompuesto::getIngredientes() const {
    VectorDinamico<std::string> ingredientes;
    for (int i = 0; i < subproductos.size(); ++i) {
        VectorDinamico<std::string> subIngs = subproductos[i]->getIngredientes();
        for (int j = 0; j < subIngs.size(); ++j) {
            ingredientes.agregar(subIngs[j]);
        }
    }
    return ingredientes;
}

void ProductoCompuesto::imprimir(std::ostream &os) const {
    os << "Producto compuesto: " << nombre << " (codigo: " << codigo << ")\n";
    VectorDinamico<std::string> ings = getIngredientes();
    os << "Producto simple"<<"\n";
    for (int i = 0; i < subproductos.size(); ++i) {
        os << "  " << subproductos[i]->getNombre()<<"\n";
    }
    os <<"\n" <<"Ingredientes: ";
    for (int i = 0; i < ings.size(); ++i) {
        os << ings[i];
        if (i < ings.size() - 1) os << ", ";
    }
    os << "\n";
}

bool ProductoCompuesto::esCompuesto() const { return true; }
