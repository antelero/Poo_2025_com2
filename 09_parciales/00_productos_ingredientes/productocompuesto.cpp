#include "productocompuesto.h"

ProductoCompuesto::ProductoCompuesto()
{}

ProductoCompuesto::ProductoCompuesto(int cod, const char *nom)
    : Producto(cod, nom) {}

ProductoCompuesto::~ProductoCompuesto() {}

void ProductoCompuesto::agregarSubproducto(Producto *p) {
    subproductos.agregar(p);
}

void ProductoCompuesto::fusionarSinDuplicados(Vector<Ingrediente> &destino, const Vector<Ingrediente> &origen) {
    for (int i = 0; i < origen.size(); i++) {
        bool existe = false;
        for (int j = 0; j < destino.size(); j++) {
            if (destino.obtener(j) == origen.obtener(i)) {
                existe = true;
                break;
            }
        }
        if (!existe)
            destino.agregar(origen.obtener(i));
    }
}

Vector<Ingrediente> ProductoCompuesto::getIngredientes() const {
    Vector<Ingrediente> todos;
    for (int i = 0; i < subproductos.size(); i++) {
        Vector<Ingrediente> sub = subproductos.obtener(i)->getIngredientes();
        fusionarSinDuplicados(todos, sub);
    }
    return todos;
}

void ProductoCompuesto::imprimirDetalle(ostream &os) const {
    os << "  Compuesto por:\n";
    for (int i = 0; i < subproductos.size(); i++) {
        const Producto* p = subproductos.obtener(i);
        os << "    > [" << p->getCodigo() << "] " << p->getNombre() << " -- ";
        Vector<Ingrediente> ings = p->getIngredientes();
        for (int j = 0; j < ings.size(); j++) {
            if (j > 0) os << ", ";
            os << ings.obtener(j);
        }
        os << "\n";
    }

}
