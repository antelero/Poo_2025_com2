#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
class Persona
{
private:
    char * nombre;
    char * telefono;
public:
    Persona(char * nombre, char * telefono);
    char * getNombre();
    char * getTelefono();

    friend std::ostream& operator<<(std::ostream& out, const Persona& a);
};

#endif // PERSONA_H
