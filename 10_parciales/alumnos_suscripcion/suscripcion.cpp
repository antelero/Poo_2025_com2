#include "suscripcion.h"

Suscripcion::Suscripcion(int cantExamenes)
{
    cantNotas=0;
    cantExamenesRequeridos = cantExamenes;
}

void Suscripcion::cargarNota(float nota) {
    if (cantNotas >= cantExamenesRequeridos) {
        std::cout << "Ya se cargaron todos los examenes.\n";
        return;
    }
    notas[cantNotas++] = nota;
}

int Suscripcion::getCantNotas() const {
    return cantNotas;
}

int Suscripcion::getCantExamenesRequeridos() const {
    return cantExamenesRequeridos;
}

void Suscripcion::transferirNotasA(Suscripcion &destino) const {
    for (int i = 0; i < cantNotas; i++)
        destino.cargarNota(notas[i]);
}
