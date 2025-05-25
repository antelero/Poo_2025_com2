#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream>

class Persona {
private:
    char* nombre;
    int edad;
    int dni;
public:
    Persona(char* nombre, int edad, int dni);

    //Suma
    Persona& operator++();

    //++ Postincremento
    Persona operator++(int);

    friend bool operator==(const Persona& lhs, const Persona& rhs);

    void mostrar() const;
    friend std::ostream& operator<<(std::ostream& os, const Persona& obj);
};

#endif // PERSONA_H
