#ifndef ALUMNO_H
#define ALUMNO_H
#include <cstring>
#include <ostream>
class Alumno
{
private:
    int dni;
    std::string  nombres;
    std::string  apellido;
    std::string  email;
public:
    Alumno(int dni, std::string  nombres,   std::string  apellido);
    virtual std::string  getCondicion() const = 0;
    std::string getNombres() const;
    std::string getApellido() const;
    std::string getEmail() ;
    friend std::ostream& operator<<(std::ostream& os, const Alumno& a) ;
};

#endif // ALUMNO_H
