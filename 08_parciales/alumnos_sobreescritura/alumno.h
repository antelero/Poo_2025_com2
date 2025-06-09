#ifndef ALUMNO_H
#define ALUMNO_H
#include <cstring>
#include <ostream>
class Alumno
{
private:
    int dni;
    char * nombres;
    char * apellido;
    char * email;
public:
    Alumno(int dni, char * nombres,   char * apellido);
    virtual char * getCondicion() const = 0;
    char *getNombres() const;
    char *getApellido() const;
    char *getEmail() ;
    friend std::ostream& operator<<(std::ostream& os, const Alumno& a) ;
};

#endif // ALUMNO_H
