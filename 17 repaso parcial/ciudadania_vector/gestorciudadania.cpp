#include "gestorciudadania.h"
#include <fstream>
#include <vector>
#include <functional>

bool GestorCiudadania::esAptoParaCiudadania(Persona* persona) {
    if (strcmp(persona->getNacionalidad(), "Italiana") == 0)
        return true;
    //Se inicia la búsqueda con la persona actual como primer nivel.
    std::vector<Persona*> nivelActual;
    nivelActual.push_back(persona);
    //Mientras haya personas en el nivel actual (ancestros a revisar)
    while (!nivelActual.empty()) {
        int cantidad = nivelActual.size();
        int italianos = 0;
        std::vector<Persona*> siguienteNivel;
        for (int i = 0; i < cantidad; ++i) {
            Persona* actual = nivelActual.front();
            nivelActual.erase(nivelActual.begin());

            Persona* p1 = actual->getPadre();
            Persona* p2 = actual->getMadre();

            if (p1) {
                siguienteNivel.push_back(p1);
                if (strcmp(p1->getNacionalidad(), "Italiana") == 0)
                    italianos++;
            }
            if (p2) {
                siguienteNivel.push_back(p2);
                if (strcmp(p2->getNacionalidad(), "Italiana") == 0)
                    italianos++;
            }
        }

        if (cantidad > 0 && italianos >= cantidad)
            return true;

        nivelActual = siguienteNivel;
    }

    return false;
}

int GestorCiudadania::contarAntepasadosItalianos(Persona* persona) {
    std::function<int(Persona*)> contar = [&](Persona* p) {
        if (!p) return 0;
        int total = 0;
        Persona* padre = p->getPadre();
        Persona* madre = p->getMadre();

        if (padre && strcmp(padre->getNacionalidad(), "Italiana") == 0)
            total++;
        if (madre && strcmp(madre->getNacionalidad(), "Italiana") == 0)
            total++;

        total += contar(padre);
        total += contar(madre);
        return total;
    };
    return contar(persona);
}

void GestorCiudadania::guardarBinario(Persona* persona, const std::string& archivo) {
    std::ofstream out(archivo, std::ios::binary);
    std::function<void(Persona*)> guardar = [&](Persona* p) {
        if (!p) return;
        strPersona per;
        strncpy(per.dni, p->getDNI(), sizeof(per.dni));
        strncpy(per.nombre, p->getNombre(), sizeof(per.nombre));
        strncpy(per.apellido, p->getApellido(), sizeof(per.apellido));
        strncpy(per.nacionalidad, p->getNacionalidad(), sizeof(per.nacionalidad));

        out.write((char*)&per, sizeof(per));
        guardar(p->getPadre());
        guardar(p->getMadre());
    };
    guardar(persona);
    out.close();
}

void GestorCiudadania::guardarTexto(Persona* persona, const std::string& archivo) {
    std::ofstream out(archivo);
    std::function<void(Persona*, int)> imprimir = [&](Persona* p, int nivel) {
        if (!p) return;
        out << std::string(nivel * 2, ' ') << "Nombre: " << p->getNombre()
            << ", DNI: " << p->getDNI()
            << ", Nacionalidad: " << p->getNacionalidad() << "\n";
        imprimir(p->getPadre(), nivel + 1);
        imprimir(p->getMadre(), nivel + 1);
    };
    imprimir(persona, 0);
    out.close();
}

bool GestorCiudadania::tieneAntepasadoConNombre(Persona* persona, const std::string& nombreBuscado) {
    std::function<bool(Persona*)> buscar = [&](Persona* p) {
        if (!p) return false;
        if (nombreBuscado == p->getNombre()) return true;
        return buscar(p->getPadre()) || buscar(p->getMadre());
    };
    return buscar(persona);
}

void GestorCiudadania::agregarPersona(Persona* persona) {
    personasRaiz.push_back(persona);
}

void GestorCiudadania::evaluarCiudadania() {
    for (Persona* persona : personasRaiz) {
        std::cout << "Evaluando a " << persona->getNombre() << " " << persona->getApellido() << " (" << persona->getDNI() << "): ";
        if (esAptoParaCiudadania(persona)) {
            std::cout << "Apto para ciudadania italiana.\n";
        } else {
            std::cout << "No cumple con los requisitos.\n";
        }
    }
}
