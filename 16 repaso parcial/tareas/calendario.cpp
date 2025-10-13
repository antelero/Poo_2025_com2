#include "calendario.h"

Calendario::Calendario(){};

void Calendario::guardarBinario(string nomArchi){
    ofstream archi(nomArchi, ios::binary);
    if(!archi){
        cout<<"Error al abrir archivo de guardado de tareas"<<endl;
    }
    TareaAux tar;
    for(auto*& act : tareas){
        strncpy(tar.desc, act->getDesc().c_str(), sizeof(tar.desc));
        strncpy(tar.fecha, act->getHora().c_str(), sizeof(tar.fecha));
        strncpy(tar.hora, act->getHora().c_str(), sizeof(tar.hora));
        tar.duracion= act->getDuracion();
        tar.tipo= act->getTipo();

        archi.write((char*)(&tar), sizeof(TareaAux));
    }
    archi.close();
}

vector<Tarea*> Calendario::tareasMasLargas(){
    if(tareas.empty()){
        cout<<"No hay actividades cargadas"<<endl;
    }
    sort(tareas.begin(), tareas.end(),
         []( Tarea* a,  Tarea* b) {
             return a->getDuracion() > b->getDuracion();
         });
    int Max = tareas.front()->getDuracion();
    vector<Tarea*> aux;
    for(auto*& act : tareas){
        if(act->getDuracion() == Max){
            aux.push_back(act);
        }
    }
    return aux;
}

void Calendario::diaConMasTarea(){
    if(tareas.empty()){
        cout<<"No hay actividades cargadas"<<endl;
    }
    map<string,int> dias;
    for (auto& act : tareas) {
        dias[act->getFecha()]++;
    }
    auto max = max_element(dias.begin(), dias.end(),
                           [](const auto& a, const auto& b) {
        return a.second < b.second;
    });
    cout<<"El dia con mas tareas es: "<<max->first<<endl;
    cout<<"Con un total de: "<<max->second<<" tareas"<<endl;
}

int Calendario::horaToMin(const string& h) {
    int hh = stoi(h.substr(0,2));
    int mm = stoi(h.substr(2,2));
    return hh*60 + mm;
}

// Tareas que se superponen
void Calendario::tareasSuperpuestas(){
    if(tareas.empty()){
        cout<<"No hay actividades cargadas"<<endl;
    }
    sort(tareas.begin(), tareas.end(),
         []( Tarea*& a,  Tarea*& b){
        if(a->getFecha()!= b->getFecha())
            return a->getFecha() < b->getFecha();
        return a->getHora() < b->getHora();
    });

    for (size_t i = 0; i + 1 < tareas.size(); i++) {
        if (tareas[i]->getFecha() == tareas[i+1]->getFecha()) {
            int inicio1 = horaToMin(tareas[i]->getHora());
            int final1 = inicio1 + tareas[i]->getDuracion();
            int inicio2 = horaToMin(tareas[i+1]->getHora());

            if (inicio2 < final1) {
                cout << "   - " << tareas[i]->getDesc()
                     << " se superpone con " << tareas[i+1]->getDesc()
                     << " en fecha " << tareas[i]->getFecha() << endl;
            }
        }
    }

}

int Calendario::getSize()
{
    this->tareas.size();
}

void Calendario::agregarTarea(Tarea * t)
{
    tareas.push_back(t);
}

void Calendario::ejecutarTodas() {
    vector<Tarea*> nuevas; // guardar tareas nuevas

    for (auto t : tareas) {
        Tarea* nueva = t->notificar();
        if (nueva != nullptr)
            nuevas.push_back(nueva);
    }
    // Agregar las nuevas al vector principal
    tareas.insert(tareas.end(), nuevas.begin(), nuevas.end());
}
