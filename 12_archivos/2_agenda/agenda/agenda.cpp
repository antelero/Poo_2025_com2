#include "agenda.h"
#include <string.h>


int Agenda::getSize()
{
    return this->personas.size();
}

Agenda Agenda::Leer()
{
    Registro1 s;
    Registro2 c;
    std::ifstream archivo, archivo2;
    archivo.open("datos_personas.dat",  std::ios::binary);
    archivo2.open("datos_personas_contactos.dat", ios::binary);
    /*
    std::cout << "BORRA PERSONAS"<< endl;
    std::cout << "PERSONAS "<< this->personas.size()<< endl;
    this->personas.clear();
    std::cout << "PERSONAS "<< this->personas.size()<< endl;
    */
    while (!archivo.eof()) {
            archivo.read((char*) &s, sizeof(s));
            if (!archivo.eof()) {
                Persona t(s.nombre, s.edad, s.dni);
                while (!archivo2.eof()) {
                        archivo2.read((char*) &c, sizeof(c));
                        if (!archivo.eof()) {
                            if (c.dni==s.dni){
                                Contacto tc(c.dni,c.tipo,c.valor);
                                t.addContacto(tc);
                            }
                        }
                }
                personas.push_back(t);
            }
    }
    std::cout << "PERSONAS FINAL "<<endl;
    for (auto it = personas.begin(); it!= personas.end();++it)
    {
        std::cout << it->getDni()<< " " <<  it->getNombre() << " " << it->getEdad() << " " << endl;
        for (auto itc = it->getContactos().begin(); itc!= it->getContactos().end();++itc)
        {
            std::cout << "----" <<itc->getDni() << " " << itc->getTipo() << itc->getValor() << endl;
        }
    }
    archivo.close();
    archivo2.close();
};
