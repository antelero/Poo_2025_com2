#include "gestor.h"
#include "noperecedero.h"
#include <iostream>
using namespace std;

Gestor::Gestor() {}

Gestor::~Gestor() {
    for (auto p : productos)
        delete p;
}

void Gestor::agregarProducto(Producto* p) {
    productos.push_back(p);
    inventario[p->getNombre()] = p;
}

void Gestor::mostrarTodos(int cantidad) const {
    double total = 0.0;

    cout << "=== Lista de productos y subtotal ===" << endl;
    for (auto p : productos) {
        double subtotal = p->calcular(cantidad);
        cout << *p << " -> Subtotal por " << cantidad
             << " $: " << subtotal << endl;
        total += subtotal;
    }

    cout << "\nTOTAL VENTA: " << total << endl;
}

void Gestor::consultarProducto(const string &nombre, int cantidad) const
{
    auto it = inventario.find(nombre);
        if (it != inventario.end()) {
            Producto* p = it->second;
            cout << "Consulta: " << *p
                 << " -> Subtotal por " << cantidad
                 << " $: " << p->calcular(cantidad) << endl;
        } else {
            cout << "El producto '" << nombre << "' no esta en el inventario." << endl;
        }
}

void Gestor::guardarArchi()
{
    // Guardar en archivo binario
    ofstream archivo("productos.dat", ios::binary);
    for (auto p : productos) {
        ProductoBin pb{};
        if (Perecedero* pp = dynamic_cast<Perecedero*>(p)) {
            pb.tipo = 1;
            strncpy(pb.nombre, pp->getNombre().c_str(), sizeof(pb.nombre));
            pb.precio = pp->getPrecio();
            pb.dias_a_caducar = pp->getDias();
            pb.tipo_producto[0] = '\0';
        } else if (NoPerecedero* np = dynamic_cast<NoPerecedero*>(p)) {
            pb.tipo = 2;
            strncpy(pb.nombre, np->getNombre().c_str(), sizeof(pb.nombre));
            pb.precio = np->getPrecio();
            pb.dias_a_caducar = 0;
            strncpy(pb.tipo_producto, np->getTipo().c_str(), sizeof(pb.tipo_producto));
        }
        archivo.write((char*)&pb, sizeof(pb));
    }
    archivo.close();
}

void Gestor::leerArchi()
{
    // Leer desde archivo
    ifstream archivo_lectura("productos.dat", ios::binary);
    ProductoBin pb;
    while (archivo_lectura.read((char*)&pb, sizeof(pb))) {
        if (pb.tipo == 1)
            agregarProducto(new Perecedero(pb.nombre, pb.precio, pb.dias_a_caducar));
        else if (pb.tipo == 2)
            agregarProducto(new NoPerecedero(pb.nombre, pb.precio, pb.tipo_producto));
        }
    archivo_lectura.close();
}

void Gestor::limpiar()
{
    this->productos.clear();
    this->inventario.clear();
}

int Gestor::getSize()
{
    this->productos.size();
}

void Gestor::obtenerTresCaros()
{
    // Ordena de mayor a menor según precio
    sort(productos.begin(), productos.end(),
         [](Producto* a, Producto* b) {
             return a->getPrecio() > b->getPrecio();
         });


    cout << "Los 3 productos mas caros:" << endl;
    for (size_t i = 0; i < 3 && i < productos.size(); ++i) {
        cout << i+1 << ". " << productos[i]->getNombre()
             << " | Precio: " << productos[i]->getPrecio() << endl;
    }
}

void Gestor::conteoPorTipo()
{
    map<string, int> conteoPorTipo;

    for (auto p : productos) {
        string tipo;
        if (dynamic_cast<Perecedero*>(p)) tipo = "Perecedero";
        else tipo = "No Perecedero";

        conteoPorTipo[tipo]++; // incrementa el contador
    }

    cout << "Cantidad de productos por tipo:" << endl;
    for (auto& par : conteoPorTipo) {
        cout << par.first << ": " << par.second << endl;
    }
}
