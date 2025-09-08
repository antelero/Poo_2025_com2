#include "curso.h"
#include <iostream>

int Curso::getCantidad()
{
    return alumnos.size();
}

Curso::Curso(std::string  nombre)
{
    this->nombre = nombre;
}

void Curso::addAlumno(Alumno *alu)
{
    alumnos.push_back(alu);
}


Alumno * Curso::getAlumno(int pos)
{
    return alumnos[pos];
}
bool compararPorApellido(Alumno* a, Alumno* b) {
    return std::string(a->getApellido()) > std::string(b->getApellido());
}
void Curso::ordenar(char orden)
{
    if (orden == 'A') {
        // Ordenar por apellido usando sort ASC
        sort(alumnos.begin(), alumnos.end(),
             [](Alumno* a, Alumno* b) {
                return std::string(a->getApellido()) < std::string(b->getApellido());
        });
    } else {
        sort(alumnos.begin(), alumnos.end(),
            compararPorApellido);
    }
}

Alumno *Curso::buscarNombre(std::string buscado)
{
    auto it = find_if(alumnos.begin(), alumnos.end(),
                      [&](Alumno* a) {
                          return buscado == std::string(a->getNombres());
                      });

    if (it != alumnos.end()) {
        return *it;
    } else {
        return NULL;
    }
}

void Curso::grabarTxt()
{
    // Abrir archivo para escribir
    std::ofstream archivo("alumnos.txt");
    if (archivo.is_open()) {
        for (auto a : alumnos) {
            archivo << *a << " | Condición: " << a->getCondicion() << std::endl;
        }
        archivo.close();
        std::cout << "Archivo alumnos.txt guardado correctamente.\n";
     } else {
        std::cout << "Error al abrir el archivo.\n";
    }
}


void Curso::grabarTxtObj()
{
    std::ofstream archivo("alumnosObj.txt");
    if (archivo.is_open()) {
        for (auto a : alumnos) {
            // Detectar tipo con dynamic_cast
            if (dynamic_cast<AlumnoNormal*>(a)) {
                AlumnoNormal* an = dynamic_cast<AlumnoNormal*>(a);
                archivo << "NORMAL," << an->getNombres() << "," << an->getApellido()
                        << "," << an->p1 << "," << an->p2 << "," << an->p3 << "," << an->final << "\n";
            }
            else if (dynamic_cast<AlumnoVocacional*>(a)) {
                AlumnoVocacional* av = dynamic_cast<AlumnoVocacional*>(a);
                archivo << "VOCACIONAL," << av->getNombres() << "," << av->getApellido()
                        << "," << av->getExamen() << "\n";
            }
            else if (dynamic_cast<AlumnoEspecial*>(a)) {
                AlumnoEspecial* ae = dynamic_cast<AlumnoEspecial*>(a);
                archivo << "ESPECIAL," << ae->getNombres() << "," << ae->getApellido();
                for (int i = 0; i < ae->getCantidad(); i++) {
                    archivo << "," << ae->getNota(i);
                }
                archivo << "\n";
            }
            else if (dynamic_cast<AlumnoLibre*>(a)) {
                AlumnoLibre* al = dynamic_cast<AlumnoLibre*>(a);
                archivo << "LIBRE," << al->getNombres() << "," << al->getApellido()
                        << "," << al->getFinal() << "," << al->getExtra() << "\n";
            }
        }
        archivo.close();
        cout << "Archivo alumnosObj.txt guardado correctamente.\n";
    }
}

void Curso::leerTxtObj()
{
    ifstream entrada("alumnosObj.txt");

    if (entrada.is_open()) {
        cout << "\nLeyendo desde archivo alumnosObj.txt:\n";
        string linea;
        while (getline(entrada, linea)) {
            string tipo;
            vector<string> palabras;
            size_t pos = 0;
            while ((pos = linea.find(",")) != string::npos) {
                palabras.push_back(linea.substr(0, pos));
                linea.erase(0, pos + 1);
            }
            palabras.push_back(linea);

            tipo = palabras[0];
            if (tipo == "NORMAL") {
                alumnos.push_back(new AlumnoNormal(0, (char*)palabras[1].c_str(), (char*)palabras[2].c_str(),
                        stoi(palabras[3]), stoi(palabras[4]), stoi(palabras[5]), stoi(palabras[6])));
            }
            else if (tipo == "VOCACIONAL") {
                alumnos.push_back(new AlumnoVocacional(0, (char*)palabras[1].c_str(), (char*)palabras[2].c_str(), stoi(palabras[3])));
            }
            else if (tipo == "ESPECIAL") {
                AlumnoEspecial* ae = new AlumnoEspecial(0, (char*)palabras[1].c_str(), (char*)palabras[2].c_str());
                for (size_t i = 3; i < palabras.size(); i++) {
                    ae->addNota(stoi(palabras[i]));
                }
                alumnos.push_back(ae);
            }
            else if (tipo == "LIBRE") {
                alumnos.push_back(new AlumnoLibre(0, (char*)palabras[1].c_str(), (char*)palabras[2].c_str(),
                        stoi(palabras[3]), stoi(palabras[4])));
            }
        }
        entrada.close();
    }
}

void Curso::limpiar()
{
    this->alumnos.clear();
}
