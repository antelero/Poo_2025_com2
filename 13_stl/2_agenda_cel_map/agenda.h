#ifndef AGENDA_H
#define AGENDA_H

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "persona.h"


class Agenda
{
private:
   // Antes: std::vector<Persona> agenda;
   // Ahora: map indexado por telefono (clave = std::string, valor = Persona)
   // Esto ordena automaticamente por telefono y permite busqueda por telefono.
   std::map<std::string, Persona> agenda;
public:
    Agenda();
    void insertar(Persona persona);
    Persona getPersXTelefono(char * numero);
    Persona getPersXTelefono2(char *numero);
    Persona getPersXNombre(char *nombre);
    Persona getPersXNombre2(char *nombre);
    void listarXTel();
    void listarXNom();
};

#endif // AGENDA_H
