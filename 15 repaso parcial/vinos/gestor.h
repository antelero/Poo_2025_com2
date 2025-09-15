#ifndef GESTOR_H
#define GESTOR_H
#include <vector>
#include <string>
#include <iostream>
#include "vino.h"
#include "vinomesa.h"
#include "vinoespecial.h"
#include "vinopremium.h"
#include <algorithm>

class Gestor
{
private:
    std::vector<Vino*> vinos;
public:
    Gestor();
    int calcularProd(int anio);
    void generarBinVinos();
    std::vector<Vino*> cargarVinosDesdeArchivo(const std::string& archivo);
    std::vector<Vino*> getVinos();
    int getSize();
    void escribirInformeAnual(const std::vector<Vino*>& vinos, int anio);
    void generarVinosDummy();
    ~Gestor();
    void obtenerTop5AniosProduccion();
    int anioMayorVenta();
    int anioMayorMonto();


};

#endif // GESTOR_H
