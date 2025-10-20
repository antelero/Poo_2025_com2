#include <iostream>
#include "obrasocial.h"
using namespace std;

int main() {
    ObraSocial os;
    os.inicializarPlanes();
    // Generar archivo con datos
    os.crearClientesBin();
    os.cargarClientes("clientes.dat");
    cout << "Top 5 usuarios que más usaron el servicio:\n";
    for (auto& c : os.top5Usuarios())
        cout << c << endl;
    cout << "\nTodas las prestaciones disponibles:\n";
    for (auto& p : os.todasLasPrestaciones())
        cout << "- " << p << endl;

    cout << "\nCantidad de usos por tipo de plan:\n";
    for (auto& [tipo, total] : os.cantidadPorPlan())
        cout << tipo << " => " << total << endl;

    cout << "\nPrestaciones comunes en todos los planes:\n";
    for (auto& p : os.prestacionesComunes())
        cout << "- " << p << endl;

    return 0;
}
