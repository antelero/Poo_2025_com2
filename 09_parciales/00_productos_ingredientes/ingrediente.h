#ifndef INGREDIENTE_H
#define INGREDIENTE_H
#include <iostream>
#include <cstring>

using namespace std;


class Ingrediente
{
private:
    char nombre[64];
public:
    Ingrediente(const char* nom);
    const char* getNombre() const;
    bool operator==(const Ingrediente& otro) const;
    friend ostream& operator<<(ostream& os, const Ingrediente& ing) {
        os << ing.nombre;
        return os;
    }
    Ingrediente();
};

#endif // INGREDIENTE_H
