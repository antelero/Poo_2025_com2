#include "tarea.h"

Tarea::Tarea(string d, string f, string h, int dur, char t){
    this->descripcion= d;
    this->fecha= f;
    this->hora= h;
    this->duracion= dur;
    this->tipo= t;
}
string Tarea::getDesc()
{
    return descripcion;
}
string Tarea::getFecha()
{
    return fecha;
}
string Tarea::getHora() {
    return hora;
}
int Tarea::getDuracion()  {
    return duracion;
}
char Tarea::getTipo() {
    return tipo;
}
