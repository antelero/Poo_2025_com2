#ifndef GESTOR_H
#define GESTOR_H

#include <fstream>
#include <string>
#include <vector>
#include "alumno.h"

// El Gestor encapsula el curso
class Gestor {
private:
    std::vector<Alumno> curso;

    // Formato binario de un Alumno: tamaño FIJO (30 bytes para el nombre).
    // Es un detalle de implementación: privado, nadie de afuera lo necesita.
    struct RegistroAlumno {
        int legajo;
        char nombre[30];
        float nota;
    };

    // Helpers privados:
    static void guardarTexto(const std::string& archivo, const std::vector<Alumno>& lista);
    static void guardarBinario(const std::string& archivo, const std::vector<Alumno>& lista);
    static std::vector<Alumno> cargarBinario(const std::string& archivo);
    static void imprimirListado(const std::vector<Alumno>& lista);
    static RegistroAlumno leerRegistro(std::ifstream& is, int n);

public:
    Gestor(std::vector<Alumno> curso);

    // vector + map + iteradores, sobre el curso ya cargado
    void demoVectorMapIteradores() const;

    // sort + find_if. Ordena "curso" IN PLACE (por eso no es const):
    void demoOrdenarYBuscar();

    // guardarTexto
    void demoPersistenciaTexto() const;

    // guardarBinario/cargarBinario (RegistroAlumno de tamaño fijo)
    void demoPersistenciaBinaria() const;

    // imprimirListado con <iomanip>
    void demoListadoFormateado() const;

    // arma su propio archivo de prueba y lo lee con seekg (acceso aleatorio).
    void demoAccesoAleatorio() const;
};

#endif // GESTOR_H


