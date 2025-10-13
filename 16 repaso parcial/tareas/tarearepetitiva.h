#ifndef TAREAREPETITIVA_H
#define TAREAREPETITIVA_H
#include <iostream>
#include <sstream>
#include "tarea.h"
#include <iomanip>   // para setw() y setfill()
using namespace std;
class TareaRepetitiva : public Tarea
{
private:
    string calcularDiaSiguiente(const string &fecha);

public:
    TareaRepetitiva(string desc, string f, string h, int d);
    Tarea *notificar();
};

#endif // TAREAREPETITIVA_H
