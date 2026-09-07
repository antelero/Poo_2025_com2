#include <vector>
#include "alumno.h"
#include "gestor.h"

int main() {
    std::vector<Alumno> curso;
    curso.emplace_back(101, "Ana Diaz",     8.5f);
    curso.emplace_back(102, "Luis Roman",   3.0f);
    curso.emplace_back(103, "Marco Sosa",   6.0f);
    curso.emplace_back(104, "Nadia Ibarra", 9.0f);

    Gestor gestor(curso);   // el Gestor toma su propia copia del curso

    gestor.demoVectorMapIteradores();
    gestor.demoListadoFormateado();      // todavía en orden de carga
    gestor.demoOrdenarYBuscar();         // ordena el curso interno in place
    gestor.demoPersistenciaTexto();      // se guarda ya ordenado
    gestor.demoPersistenciaBinaria();
    gestor.demoAccesoAleatorio();

    return 0;
}
