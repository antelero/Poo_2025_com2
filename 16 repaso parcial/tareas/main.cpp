#include <iostream>
#include "calendario.h"
#include "tareaarchivo.h"
#include "tareanormal.h"
#include "tarearepetitiva.h"
using namespace std;

int main()
{
    Calendario calendario;

    calendario.agregarTarea(new TareaNormal("Reunion con equipo", "20251011", "100000", 60));
    calendario.agregarTarea(new TareaRepetitiva("Ejercicio diario", "20251011", "070000", 90));
    calendario.agregarTarea(new TareaArchivo("Enviar informe", "20251011", "120000", 45));
    calendario.agregarTarea(new TareaNormal("Reunion con otro equipo", "20251012", "103000", 60));
    calendario.agregarTarea(new TareaNormal("Reunion con proveedores", "20251012", "110000", 30));
    calendario.agregarTarea(new TareaArchivo("Enviar informe de avance", "20251011", "120000", 45));

    cout << "Tareas " << calendario.getSize()<<endl;
    calendario.ejecutarTodas();
    cout << "tareas " << calendario.getSize()<<endl;
    calendario.guardarBinario("datos.dat");
    auto mayores = calendario.tareasMasLargas();
    cout << "\nTarea con mayor duracion:\n";
    for (auto t : mayores)
        cout << t->getDesc() << " (" << t->getDuracion() << " min)\n";
    calendario.diaConMasTarea();
    cout << "\nTareas superpuestas:\n";
    calendario.tareasSuperpuestas();
    return 0;
}



