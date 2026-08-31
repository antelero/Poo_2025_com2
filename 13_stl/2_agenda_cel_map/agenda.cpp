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
    // La clave del map es el telefono. insert() no requiere que Persona
    // tenga constructor por defecto (a diferencia de agenda[clave] = persona).
    std::string clave = persona.getTelefono();
    //lista de inicialización
    this->agenda.insert({persona.getTelefono(), persona});
    //this->agenda.insert(std::make_pair(clave, persona));
    //Si la clave es el teléfono de la persona, también:
    //this->agenda.emplace(persona.getTelefono(), persona);
}

void Agenda::listarXTel()
{
    // Ya no hace falta sort(): el map mantiene sus elementos ordenados
    // por clave (telefono) automaticamente.
    for (auto& par : agenda)
        std::cout << par.second << std::endl;
}

void Agenda::listarXNom()
{
    // El map esta ordenado por telefono, no por nombre, asi que para listar
    // por nombre se copian los valores a un vector auxiliar y se ordenan ahi.
    std::vector<Persona> temp;
    for (auto& par : agenda)
        temp.push_back(par.second);

    std::sort(temp.begin(), temp.end(),
              [](Persona& p1, Persona& p2) {
                  return strcmp(p1.getNombre(), p2.getNombre()) < 0;
              });

    for (auto& p : temp)
        std::cout << p << std::endl;
}

Persona Agenda::getPersXTelefono(char *numero)
{
    // Busqueda directa por clave: O(log n), en vez de find_if lineal O(n)
    auto it = agenda.find(numero);
    if (it != agenda.end())
    {
        std::cout << "Si, ese numero existe en la agenda y es " << it->second << std::endl;
        return it->second;
    }
    else
    {
        std::cout << "No, ese numero "<< numero <<" no existe en la agenda" <<std::endl;
        return Persona((char*)"(no encontrado)", (char*)"-");
    }
}

Persona Agenda::getPersXTelefono2(char *numero)
{
    // Version alternativa recorriendo el map (equivalente al find() de arriba,
    // se deja solo para mostrar la comparacion con la busqueda lineal)
    for (auto& par : agenda)
    {
        if (strcmp(par.second.getTelefono(), numero) == 0)
        {
            std::cout << "Encontro x tel "<< par.second << std::endl;
            return par.second;
        }
    }
    return Persona((char*)"(no encontrado)", (char*)"-");
}


Persona Agenda::getPersXNombre2(char *nombre)
{
    // El nombre no es la clave del map, asi que sigue
    // siendo busqueda lineal
    auto it = std::find_if(
                            this->agenda.begin(),
                            this->agenda.end(),
                            [&nombre](std::pair<const std::string, Persona>& par) -> bool {
                                return (strcmp(par.second.getNombre(), nombre) == 0);
                            }
            );
            if (it != agenda.end())
            {
                std::cout << "Si, ese nombre existe en la agenda y es " << it->second <<std::endl;
                return it->second;
            }
            else
            {
                std::cout << "No, ese nombre "<< nombre <<" no existe en la agenda" <<std::endl;
                return Persona((char*)"(no encontrado)", (char*)"-");
            }
}

Persona Agenda::getPersXNombre(char *nombre)
{
    for (auto& par : agenda)
    {
        if (strcmp(par.second.getNombre(), nombre) == 0)
        {
            std::cout << "Encontro x nombre "<< par.second << std::endl;
            return par.second;
        }
    }
    return Persona((char*)"(no encontrado)", (char*)"-");
}
