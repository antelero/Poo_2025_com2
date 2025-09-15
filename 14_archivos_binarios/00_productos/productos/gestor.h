#ifndef GESTOR_H
#define GESTOR_H

#include <vector>
#include <map>
#include "producto.h"
#include "perecedero.h"
#include "noperecedero.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>

class Gestor {
    std::vector<Producto*> productos;
    std::map<std::string, Producto*> inventario;

public:
    Gestor();
    ~Gestor();

    void agregarProducto(Producto* p);
    void mostrarTodos(int cantidad) const;
    void consultarProducto(const string &nombre, int cantidad) const;

    void guardarArchi();
    void leerArchi();
    void limpiar();
    int getSize();
    void obtenerTresCaros();
    void conteoPorTipo();
};

#endif
