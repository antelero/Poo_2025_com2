#ifndef AGENDA_H
#define AGENDA_H

#include <iostream>
#include <map>
#include <vector>
#include "persona.h"


class Agenda
{
private:
    std::vector<Persona> agenda;

public:
    Agenda();
    void insertar(Persona persona);
    //Obtener persona por Telefono
    Persona getPersXTelefono(char * numero);
    Persona getPersXTelefono2(char *numero);
    //Obtener persona por nombre
    Persona getPersXNombre(char *nombre);
    Persona getPersXNombre2(char *nombre);
    //Listados
    Persona listarXTel();
    Persona listarXNom();
};

#endif // AGENDA_H
