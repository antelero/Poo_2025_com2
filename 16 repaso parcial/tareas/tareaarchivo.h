#ifndef TAREAARCHIVO_H
#define TAREAARCHIVO_H
#include <iostream>
#include "tarea.h"
#include <fstream>
using namespace std;
class TareaArchivo : public Tarea
{
public:
    TareaArchivo(string d, string f, string h, int dur);
    Tarea *notificar();
};

#endif // TAREAARCHIVO_H
