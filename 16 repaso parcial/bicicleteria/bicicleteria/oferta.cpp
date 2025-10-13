#include "oferta.h"

Oferta::Oferta(int n, const char *d) : Item(n, d)
{

}

void Oferta::agregarItem(Item *i)
{
    this->items.push_back(i);
}

double Oferta::getPrecio() const
{
    double total = 0;
    for (auto * p : items)
        total += p->getPrecio();
    return total * 0.8;
}


std::ostream& operator<<(std::ostream& os, const Oferta& o) {
    os << "Oferta " << o.getNumero() << " (" << o.getDescripcion() << "): ";
       for (size_t i = 0; i < o.items.size(); ++i) {
           os << o.items[i]->getDescripcion();
           if (i < o.items.size() - 1) os << ", ";
       }
       os << " | Precio total: $" << o.getPrecio();
       return os;
}
