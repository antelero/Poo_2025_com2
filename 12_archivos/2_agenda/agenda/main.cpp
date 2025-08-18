#include <QCoreApplication>
#include <persona.h>
#include <agenda.h>

int main()
{


    // Crear persona con argumentos
    Persona  p1 =  Persona("Luis", 21,25907280);
    // Obtener su edad
    int edad = p1.getEdad();
    Contacto c1(25907280,"WS","3435508661");
    Contacto c2(25907280,"EM","lmbrambilla@gmail.com");

    p1.addContacto(c1);
    p1.addContacto(c2);

    std::cout << edad << std::endl;

    // Crear otra persona, sin argumentos
    Persona  p2=  Persona();

    // Establecer valores por separado
    p2.setEdad(1);
    p2.setNombre("John Galt");
    p2.setDni(4924540);
    Contacto c21(4924540,"WS","3435508662");
    Contacto c22(4924540,"EM","ggg@gmail.com");
    p2.addContacto(c21);
    p2.addContacto(c22);
/*
    std::cout << p2.getNombre() << std::endl;
    for(auto it = p2.getContactos().begin();it!=p2.getContactos().end();++it)
    {
        std::cout << it->getValor()<< std::endl;
    }
*/
    Agenda * agenda = new Agenda();
    agenda->addPersona(p1);
    agenda->addPersona(p2);
    agenda->addPersona(Persona("jose", 33,2332));

    vector<Persona> perso = agenda->getPersonas();
    cout << "-- cantidad de elementos " << agenda->getSize() << "--"<< endl;
    for (auto it = perso.begin(); it!= perso.end();++it)
    {

        std::cout << it->getDni()<< " " <<  it->getNombre() << " " << it->getEdad() << std::endl;
        vector<Contacto> conta = it->getContactos();
        std::cout << "--cantidad " << conta.size() << endl;
        for (auto itc = conta.begin(); itc!= conta.end();++itc)
        {
            std::cout << "---- " << itc->getTipo()<< " " <<  itc->getValor() << endl;

        }
    }
    agenda->Guardar();
    agenda->Leer();
    std::cout << "FIN"<< endl;
    return 0;
}
