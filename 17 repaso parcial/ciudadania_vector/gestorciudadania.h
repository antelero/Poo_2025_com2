#ifndef GESTORCIUDADANIA_H
#define GESTORCIUDADANIA_H

#include "persona.h"
#include <string>
#include <vector>
#include <iostream>

struct strPersona
{
char dni[20];
char nombre[200];
char apellido[200];
char nacionalidad[200];
};

class GestorCiudadania
{
private:
    std::vector<Persona*> personasRaiz; // cada raíz representa un árbol genealógico

public:
    bool esAptoParaCiudadania(Persona* persona);
    int contarAntepasadosItalianos(Persona* persona);
    void guardarBinario(Persona* persona, const std::string& archivo);
    void guardarTexto(Persona* persona, const std::string& archivo);
    bool tieneAntepasadoConNombre(Persona* persona, const std::string& nombreBuscado);

    void agregarPersona(Persona* persona);
    void evaluarCiudadania();
};

#endif // GESTORCIUDADANIA_H


