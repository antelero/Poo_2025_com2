#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
class Persona {
    char nombre[30];
    char apellido[30];
    char direccion[50];
    vector<Contacto> contactos;

public:
    Persona() {
        nombre[0] = '\0';
        apellido[0] = '\0';
        direccion[0] = '\0';
    }

    const char* getNombre() const;

    void cargarDesdeTeclado();

    void mostrar() const;

    void guardarBinario(ofstream& out) const;

    void cargarBinario(ifstream& in);
};

#endif // PERSONA_H
