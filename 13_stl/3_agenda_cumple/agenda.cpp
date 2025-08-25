#include "agenda.h"
#include <vector>
#include <utility>
#include <map>


Agenda::Agenda()
{
}

void Agenda::insertar(Fecha fecha, Persona persona) {
    this->agenda.insert(std::make_pair(fecha, persona));
}

std::vector<Persona> Agenda::listarPersonasQueCumplen(Fecha fecha){
    std::vector<Persona> resultado;

    std::pair<std::multimap<Fecha,Persona>::iterator, std::multimap<Fecha,Persona>::iterator> ppp;

    ppp = this->agenda.equal_range(fecha);

    for (std::multimap<Fecha,Persona>::iterator it2 = ppp.first;
           it2 != ppp.second;
           ++it2) {

        resultado.push_back(it2->second);
    }

    return resultado;
}

//Recorriendo todos los elementos
void Agenda::listarPersonasQueCumplen2(Fecha fecha)
{

    for (auto i : agenda){
        if (i.first==fecha){
            std::cout << (i.second).getNombre()<<" " << i.first<<std::endl;

        };
}

}

//Recorriendo por limite inferior y superior del valor dado
void Agenda::listarPersonasQueCumplen3(Fecha fecha)
{
    auto itr1 = agenda.lower_bound(fecha);
    auto itr2 = agenda.upper_bound(fecha);
    while (itr1 != itr2)
       {
           if (itr1->first == fecha)
               std::cout << (itr1->second).getNombre()<<" " << itr1->first<<std::endl;
           itr1++;
       }

}
