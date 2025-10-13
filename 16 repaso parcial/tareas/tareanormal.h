#ifndef TAREANORMAL_H
#define TAREANORMAL_H
#include <iostream>

#include "tarea.h"
using namespace std;
class TareaNormal : public Tarea
{
private:
    int duracion;
public:
    TareaNormal(string desc, string f, string h, int d);
    Tarea *notificar();
};

#endif // TAREANORMAL_H
