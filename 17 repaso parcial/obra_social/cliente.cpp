#include "cliente.h"

Cliente::Cliente()
{
}

Cliente::Cliente(int _id, const char *_nombre, char _tipo, int _cant, Plan *_plan) {

    id = _id;
    strcpy(nombre, _nombre);
    tipo = _tipo;
    cantidad = _cant;
    plan = _plan;
}

int Cliente::getCantidad() const { return cantidad; }

char Cliente::getTipo() const { return tipo; }

const char *Cliente::getNombre() const { return nombre; }

bool Cliente::tienePrestacion(const string &p) const {
    return plan && plan->tienePrestacion(p);
}

ostream& operator<<(ostream& os, const Cliente& c) {
    os << "ID: " << c.id
       << " | Nombre: " << c.nombre
       << " | Tipo: " << c.tipo
       << " | Cantidad: " << c.cantidad;
    return os;
}
