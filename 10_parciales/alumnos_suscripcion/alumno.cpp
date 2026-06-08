#include "alumno.h"
#include "suscripcion.h"

Alumno::Alumno(int codigo, const char *nombre, const char *apellido,
               Suscripcion *suscripcion) {
  this->codigo = codigo;
  this->suscripcion = suscripcion;
  strncpy(this->nombre, nombre, 49);
  this->nombre[49] = '\0';
  strncpy(this->apellido, apellido, 49);
  this->apellido[49] = '\0';
}

Alumno::~Alumno() {
    delete suscripcion;
}

int Alumno::getCodigo() const {
    return codigo;
}

const char *Alumno::getNombre() const {
    return nombre;
}

const char *Alumno::getApellido() const {
    return apellido;
}

const char *Alumno::getTipo() const {
    return suscripcion->getTipo();
}

bool Alumno::aprobo() const {
    return suscripcion->aprobo();
}

float Alumno::getPromedio() const {
    return suscripcion->getPromedio();
}

void Alumno::cargarNota(float nota) {
    suscripcion->cargarNota(nota);
}

void Alumno::upgradeSuscripcion(const char *nuevoTipo) {
    if (strcmp(suscripcion->getTipo(), "Invitado") != 0) {
        std::cout << "Error: solo los invitados pueden cambiar de suscripcion.\n";
        return;
    }

    Suscripcion* nueva = nullptr;

    if (strcmp(nuevoTipo, "Medio") == 0)
        nueva = new SuscripcionMedio();
    else if (strcmp(nuevoTipo, "Premium") == 0)
        nueva = new SuscripcionPremium();
    else {
        std::cout << "Error: tipo de suscripcion invalido.\n";
        return;
    }

    // Transfiere notas previas al nuevo tipo
    suscripcion->transferirNotasA(*nueva);

    // Cambio de estado en runtime
    delete suscripcion;
    suscripcion = nueva;
}
