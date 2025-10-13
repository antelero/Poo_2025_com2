#ifndef TAREA_H
#define TAREA_H
#include <string>
#include <iostream>
using namespace std;
class Tarea
{
private:
    string descripcion;
    string fecha;
    string hora;
    int duracion;
    char tipo;

public:
    Tarea(string d, string f, string h, int dur, char t);
    string getDesc();
    string getFecha();
    string getHora();
    int getDuracion() ;
    char getTipo();
    virtual Tarea* notificar()=0;
};

#endif // TAREA_H

