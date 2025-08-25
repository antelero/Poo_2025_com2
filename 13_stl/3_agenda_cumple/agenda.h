#ifndef AGENDA_H
#define AGENDA_H

#include <iostream>
#include <map>
#include <vector>
#include "persona.h"
#include "fecha.h"
#include <iterator>

class Agenda
{
private:
    std::multimap<Fecha,Persona> agenda;
public:
    Agenda();
    void insertar(Fecha fecha, Persona persona);
    std::vector<Persona> listarPersonasQueCumplen(Fecha fecha);

    //Enlace
    //https://www.geeksforgeeks.org/traverse-values-given-key-multimap/
    void listarPersonasQueCumplen2(Fecha fecha);
    void listarPersonasQueCumplen3(Fecha fecha);
};

#endif // AGENDA_H
