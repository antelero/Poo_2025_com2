#include "agenda.h"
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <string.h>

Agenda::Agenda()
{
}

void Agenda::insertar(Persona persona) {
    this->agenda.push_back(persona);
}

bool comparPorTelefono(Persona & per1, Persona & per2) {
    return strcmp(per1.getTelefono(), per2.getTelefono()) < 0;
}

Persona Agenda::listarXTel()
{
    std::sort(agenda.begin(), agenda.end(), comparPorTelefono);
    for (int i=0; i<agenda.size(); ++i)
        std::cout << agenda[i] << std::endl;

};

Persona Agenda::listarXNom()
{
    std::sort(agenda.begin(), agenda.end(),
              []( Persona& p1,  Persona& p2) {
                          return strcmp(p1.getNombre(), p2.getNombre()) < 0;
                      });
    for (int i=0; i<agenda.size(); ++i)
        std::cout << agenda[i] << std::endl;

};

Persona Agenda::getPersXTelefono(char *numero)
{
    auto it = std::find_if(
                            this->agenda.begin(),
                            this->agenda.end(),
                            [&numero](Persona p1) -> bool {return (strcmp(p1.getTelefono(), numero) == 0); }
            );
            if (it != agenda.end())
            {
                std::cout << "Si, ese numero existe en la agenda y es " << *it <<std::endl;
            }
            else
            {
                std::cout << "No, ese numero "<< numero <<" no existe en la agenda" <<std::endl;
            }

}

Persona Agenda::getPersXTelefono2(char *numero)
{
    for (int i=0; i<agenda.size(); ++i)
    {
        if (strcmp(agenda[i].getTelefono(), numero) == 0)
        {
            std::cout << "Encontro x tel "<< agenda[i] << std::endl;
            break;
        }
    }

}


Persona Agenda::getPersXNombre2(char *nombre)
{
    auto it = std::find_if(
                            this->agenda.begin(),
                            this->agenda.end(),
                            [&nombre](Persona p1) -> bool {return (strcmp(p1.getNombre(), nombre) == 0); }
            );
            if (it != agenda.end())
            {
                std::cout << "Si, ese nombre existe en la agenda y es " << *it <<std::endl;
            }
            else
            {
                std::cout << "No, ese nombre "<< nombre <<" no existe en la agenda" <<std::endl;
            }

}

Persona Agenda::getPersXNombre(char *nombre)
{
    for (int i=0; i<agenda.size(); ++i)
    {
        if (strcmp(agenda[i].getNombre(),nombre)== 0)
        {
            std::cout << "Encontro x nombre "<< agenda[i] << std::endl;
            break;
        }
    }

}
