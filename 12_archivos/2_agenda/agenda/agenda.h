#ifndef AGENDA_H
#define AGENDA_H


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Agenda {
    string archivo;

public:
    Agenda(const string& nombreArchivo) : archivo(nombreArchivo) {}

    void agregarPersona() {
        Persona p;
        p.cargarDesdeTeclado();

        ofstream out(archivo, ios::binary | ios::app);
        if (out.is_open()) {
            p.guardarBinario(out);
            out.close();
            cout << "Persona guardada exitosamente.\n";
        } else {
            cout << "Error al abrir el archivo.\n";
                            }
                        }

                        void buscarPersona() {
                            char nombreBuscado[30];
                            cout << "Ingrese nombre a buscar: ";
                            cin.getline(nombreBuscado, 30);

                            ifstream in(archivo, ios::binary);
                            if (!in.is_open()) {
                                cout << "No se pudo abrir el archivo.\n";
                                return;
                            }

                            Persona p;
                            bool encontrado = false;
                            while (in.peek() != EOF) {
                                p.cargarBinario(in);
                                if (strcmp(p.getNombre(), nombreBuscado) == 0) {
                                    p.mostrar();
                                    encontrado = true;
                                }
                            }

                            if (!encontrado) {
                                cout << "Persona no encontrada.\n";
                            }

                            in.close();
                        }
                    };


#endif // AGENDA_H
