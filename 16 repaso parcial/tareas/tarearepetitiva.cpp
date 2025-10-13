#include "tarearepetitiva.h"

TareaRepetitiva::TareaRepetitiva(string desc, string f, string h, int d): Tarea(desc, f, h, d, 'R')
{}

Tarea *TareaRepetitiva::notificar()
{
    cout << "Ejecutando: " << getDesc() << " fecha " << getFecha() << endl;
    string nuevaFecha = calcularDiaSiguiente(getFecha());
    cout << "Generando nueva tarea para " << nuevaFecha << endl;
    Tarea* Manana = new TareaRepetitiva(getDesc(), nuevaFecha, getHora(), getDuracion());
    return Manana;

}

string TareaRepetitiva::calcularDiaSiguiente(const string& fecha) {
    int anio = stoi(fecha.substr(0,4));
    int mes  = stoi(fecha.substr(4,2));
    int dia  = stoi(fecha.substr(6,2));
    dia++; //incremento el dia
    std::string nueva =
            std::to_string(anio) +
            (mes < 10 ? "0" + std::to_string(mes) : std::to_string(mes)) +
            (dia < 10 ? "0" + std::to_string(dia) : std::to_string(dia));
    return nueva;
}

