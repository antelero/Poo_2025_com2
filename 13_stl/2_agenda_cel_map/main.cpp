#include <iostream>
#include <vector>

#include "persona.h"
#include "agenda.h"
#include <map>

using namespace std;

int main()
{
    Agenda agenda = Agenda();

    agenda.insertar(Persona("Juan Orzales", "0343-1111"));
    agenda.insertar(Persona("Pedro Garcia", "0343-1133"));
    agenda.insertar(Persona("Oliver Ato", "0343-1122"));
    agenda.insertar( Persona("Antonio Andera", "0343-1144"));
    agenda.insertar(Persona("Salvador Alí", "0343-1166"));
    agenda.insertar(Persona("Roberto Sanchez", "0343-1155"));
    agenda.insertar(Persona("Sergio Deaca", "0343-1188"));
    agenda.insertar(Persona("Aquiles Canto", "0343-1199"));
    agenda.insertar(Persona("Santiago Martinez", "0343-0000"));

    agenda.insertar(Persona("Otro Juan", "0343-1177"));

    cout << "Listar por Nombre" << endl;
    agenda.listarXNom();
    cout << "Listar por telefono" << endl;
    agenda.listarXTel();

    char * numero= "0343-1111";

    cout << "Buscar por telefono" << endl;

    cout<< endl;
    cout << "Buscar por telefono "<< endl;
    Persona p = agenda.getPersXTelefono(numero);
    Persona p1 = agenda.getPersXTelefono("0343-2222");
    Persona p2 = agenda.getPersXTelefono("0343-1133");
    Persona p3 = agenda.getPersXTelefono2("0343-1177");

    cout<< endl;
    cout << "Buscar por nombre " << endl;
    Persona p4 = agenda.getPersXNombre("Roberto Sanchez");
    Persona p5 = agenda.getPersXNombre2("Aquiles Canto");
    Persona p6 = agenda.getPersXNombre2("Firulais");
    cout << endl;

    return 0;
}
