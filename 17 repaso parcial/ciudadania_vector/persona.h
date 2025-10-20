#ifndef PERSONA_H
#define PERSONA_H

#include <cstring>

class Persona {
private:
    char dni[20];
    char nombre[200];
    char apellido[200];
    char nacionalidad[200];
    Persona* padre;
    Persona* madre;

public:
    Persona(const char* dni, const char* nombre, const char* apellido, const char* nacionalidad);

    void setPadre(Persona* p);
    void setMadre(Persona* m);

    Persona* getPadre() const;
    Persona* getMadre() const;

    const char* getDNI() const;
    const char* getNombre() const;
    const char* getApellido() const;
    const char* getNacionalidad() const;
};

#endif
