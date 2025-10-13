#ifndef CALENDARIO_H
#define CALENDARIO_H

#include <vector>
#include "tarea.h"
#include <map>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

struct TareaAux {
    char desc[200];
    char fecha[9];//formato yyyymmdd
    char hora[7];//formato hhmmss
    int duracion;
    char tipo;
};

class Calendario
{
private:
    vector<Tarea*> tareas;
    int horaToMin(const string &h);
public:
    Calendario();
    void guardarBinario(string nomArchi);
    vector<Tarea *> tareasMasLargas();
    void diaConMasTarea();
    void tareasSuperpuestas();
    int getSize();
    void agregarTarea(Tarea *);
    void ejecutarTodas();
};

#endif // CALENDARIO_H
