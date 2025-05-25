#include "persona.h"

Persona::Persona(char* nombre, int edad, int dni){
    this->nombre = nombre;
    this->edad = edad;
    this->dni=dni;
}

//Sobrecarga del operador ++ para postincremento
//Crea una copia temporal del objeto, incrementa la edad
//y retorna la copia temporal.
Persona Persona::operator++(int) {
    Persona temp = *this;
    ++edad;
    return temp;
}

std::ostream& operator<<(std::ostream& os, const Persona& obj){
    os <<  obj.nombre << " DNI: " << obj.dni << ", Edad: " << obj.edad;
    return os;
}
