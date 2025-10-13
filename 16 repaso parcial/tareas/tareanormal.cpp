#include "tareanormal.h"

TareaNormal::TareaNormal(string desc, string f, string h, int d): Tarea(desc, f, h, d, 'N')
{}

Tarea* TareaNormal::notificar(){
    cout<<"Se debe realizar la siguiente tarea: "
       <<getDesc()<<endl;
    return nullptr;
}
