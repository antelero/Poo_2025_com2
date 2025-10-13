#include "tareaarchivo.h"

TareaArchivo::TareaArchivo(string desc, string f, string h, int d): Tarea(desc, f, h, d, 'A')
{}
Tarea* TareaArchivo::notificar(){
    string nomArchi = "noti.txt";
    ofstream Archi(nomArchi);
    if(!Archi){
        cout<<"Error al abrir archivo de notificacion de tarea"<<getDesc()<<endl;
    }
    Archi<<"Se ejecuto: "<<getDesc()<<endl;
    return nullptr;
}
