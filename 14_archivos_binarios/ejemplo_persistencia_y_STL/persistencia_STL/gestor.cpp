#include "gestor.h"
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <sstream>
#include <stdexcept>

Gestor::Gestor(std::vector<Alumno> curso)
{
    this->curso = curso;
}

// ---------------------- TEXTO ----------------------

void Gestor::guardarTexto(const std::string& archivo, const std::vector<Alumno>& lista) {
    std::ofstream os(archivo);         // modo texto por defecto
    if (!os) throw std::runtime_error("No se pudo abrir " + archivo);

    for (const auto& a : lista) {
        // un campo por linea, separado por ';' -> facil de leer a ojo
        os << a.getLegajo() << ';' << a.getNombre() << ';' << a.getNota() << '\n';
    }
}

// --------------------- BINARIO ----------------------

void Gestor::guardarBinario(const std::string& archivo, const std::vector<Alumno>& lista) {
    std::ofstream os(archivo, std::ios::binary);   // clave: ios::binary
    if (!os) throw std::runtime_error("No se pudo abrir " + archivo);

    for (const auto& a : lista) {
        RegistroAlumno r{};   // {} deja todo en 0, incluido el relleno del nombre
        r.legajo = a.getLegajo();
        std::strncpy(r.nombre, a.getNombre().c_str(), sizeof(r.nombre) - 1);
        r.nota = a.getNota();

        // UN solo write: el struct es de tamaño fijo, se manda tal cual está en memoria
        os.write((char*)(&r), sizeof(r));
    }
}

std::vector<Alumno> Gestor::cargarBinario(const std::string& archivo) {
    std::ifstream is(archivo, std::ios::binary);
    if (!is) throw std::runtime_error("No se pudo abrir " + archivo);

    std::vector<Alumno> lista;
    RegistroAlumno r;

    // UN solo read por registro, mismo tamaño fijo que al escribir
    while (is.read((char*)(&r), sizeof(r))) {
        lista.emplace_back(r.legajo, std::string(r.nombre), r.nota);
    }
    return lista;
}

// Salto directo al registro n, sin leer los anteriores (acceso aleatorio).
Gestor::RegistroAlumno Gestor::leerRegistro(std::ifstream& is, int n) {
    RegistroAlumno r;
    is.seekg(n * sizeof(r));
    is.read((char*)(&r), sizeof(r));
    return r;
}


void Gestor::imprimirListado(const std::vector<Alumno>& lista) {
    using std::cout;
    using std::left;
    using std::right;
    using std::setw;

    // guardamos el formato de cout para restaurarlo al final: fixed y
    // setprecision quedan "pegados" al stream hasta que alguien los cambia
    std::ios estadoPrevio(nullptr);
    estadoPrevio.copyfmt(cout);

    cout << left  << setw(8)  << "Legajo"
         << left  << setw(16) << "Nombre"
         << right << setw(8)  << "Nota" << '\n';
    cout << std::string(32, '-') << '\n';

    for (const auto& a : lista) {
        cout << left  << setw(8)  << a.getLegajo()
             << left  << setw(16) << a.getNombre()
             << right << setw(8)  << std::fixed << std::setprecision(1) << a.getNota()
             << '\n';
    }
    // dejamos cout como estaba antes de entrar
    cout.copyfmt(estadoPrevio);
}

// ==================== Demos públicas ====================

void Gestor::demoVectorMapIteradores() const {
    std::cout << "=== Curso (orden de carga) ===\n";
    for (const auto& a : curso) {
        // range-for = iteradores por debajo
        std::cout << a << '\n';
    }

    // el índice se arma DESPUÉS de cargar todo el vector, para que estas
    // direcciones de memoria no se invaliden si el vector reubicara datos
    std::map<int, const Alumno*> indice;
    for (const auto& a : curso)
        indice[a.getLegajo()] = &a;

    std::cout << "\n=== Buscar legajo 103 (map) ===\n";
    auto it = indice.find(103);
    if (it != indice.end())
        std::cout << *(it->second) << '\n';
}

void Gestor::demoOrdenarYBuscar() {
    std::sort(curso.begin(),
              curso.end(),
              [](const Alumno& a, const Alumno& b) { return a.getNota() > b.getNota(); });

    std::cout << "\n=== Ranking por nota ===\n";
    for (const auto& a : curso)
        std::cout << a << '\n';

    auto aplazado = std::find_if(curso.begin(),
                                 curso.end(),
                                [](const Alumno& a) { return a.getNota() < 4.0f; });
    std::cout << "\n=== Primer aplazado ===\n";
    if (aplazado != curso.end()) std::cout << *aplazado << '\n';
    else std::cout << "No hay aplazados.\n";

    float suma = std::accumulate(curso.begin(),
                                 curso.end(),
                                 0.0f,
                                [](float acc, const Alumno& a) { return acc + a.getNota(); });
    std::cout << "\nPromedio general: " << (suma / curso.size()) << '\n';
}

void Gestor::demoPersistenciaTexto() const {
    std::cout << "\n=== Persistencia en TEXTO ===\n";
    guardarTexto("curso.txt", curso);
    std::cout << "Guardado curso.txt\n";
}

void Gestor::demoPersistenciaBinaria() const {
    std::cout << "\n=== Persistencia en BINARIO ===\n";
    guardarBinario("curso.dat", curso);
    std::cout << "Guardado curso.dat\n";

    auto releido = cargarBinario("curso.dat");
    std::cout << "\n=== Releido desde binario ===\n";
    for (const auto& a : releido) std::cout << a << '\n';
}

void Gestor::demoListadoFormateado() const {
    std::cout << "\n=== Listado formateado (setw/left/right) ===\n";
    imprimirListado(curso);
}

void Gestor::demoAccesoAleatorio() const {
    std::cout << "\n=== Acceso aleatorio (seekg) ===\n";

    // arma su propio archivo de prueba, con orden fijo y conocido,
    // reusando el MISMO struct que usa guardarBinario/cargarBinario
    {
        std::ofstream os("curso_prueba.dat", std::ios::binary);
        RegistroAlumno datos[] = {
            {101, "Ana Diaz",     8.5f},
            {102, "Luis Roman",   3.0f},
            {103, "Marco Sosa",   6.0f},
            {104, "Nadia Ibarra", 9.0f},
        };
        for (auto& r : datos) os.write((char*)(&r), sizeof(r));
    }

    std::ifstream is("curso_prueba.dat", std::ios::binary);

    auto r2 = leerRegistro(is, 2);   // directo al #2, sin pasar por el 0 ni el 1
    std::cout << "Registro #2 -> " << r2.legajo << " " << r2.nombre << " - nota: " << r2.nota << '\n';

    auto r0 = leerRegistro(is, 0);
    std::cout << "Registro #0 -> " << r0.legajo << " " << r0.nombre << " - nota: " << r0.nota << '\n';
}
