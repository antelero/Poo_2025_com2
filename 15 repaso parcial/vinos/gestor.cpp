#include "gestor.h"
#include <fstream>
#include <iostream>
#include <map>
struct regVino {
    int nro;
    char tipo;
    int cantidad_litros;
    int anio_produccion;
};


Gestor::Gestor()
{

}

int Gestor::calcularProd(int anio) {
    int acu = 0;
    for (const auto& vino : vinos) {
        // Aquí asumiendo que getLtsVenta() devuelve litros que se pueden vender
        acu += vino->getLtsVenta(anio);
    }
    return acu;
}

void Gestor::generarBinVinos()
{
    // Abrir un archivo binario para escritura
    std::ofstream archivo("vinos.bin", std::ios::binary);
    if (!archivo) {
            std::cout << "No se pudo abrir el archivo para escritura." << std::endl;

    }
    // Datos ficticios de la empresa vitivinícola
    regVino datos[] = {
            {1, 'M', 500, 2020},
            {2, 'P', 300, 2021},
            {3, 'E', 200, 2022},
            {4, 'M', 700, 2020},
            {5, 'P', 400, 2021},
        };
     // Escribir los datos en el archivo binario
     for (const regVino& vino : datos) {
            archivo.write(reinterpret_cast<const char*>(&vino), sizeof(regVino));
        }
     // Cerrar el archivo
     archivo.close();
     std::cout << "Archivo 'vinos.bin' creado exitosamente con datos ficticios." << std::endl;
}

void Gestor::generarVinosDummy()
{

    // Datos ficticios de la empresa vitivinícola
    regVino datos[] = {
            {1, 'M', 500, 2020},
            {2, 'P', 300, 2021},
            {3, 'E', 200, 2022},
            {4, 'M', 700, 2020},
            {5, 'P', 400, 2021},
        };

     // Escribir los datos en el archivo binario
     for (const regVino& vino : datos) {
         if (vino.tipo == 'M') {
             vinos.push_back(new VinoMesa(vino.nro, vino.cantidad_litros, vino.anio_produccion));
         } else if (vino.tipo == 'P') {
             vinos.push_back(new VinoPremium(vino.nro, vino.cantidad_litros, vino.anio_produccion));
         } else if (vino.tipo == 'E') {
             vinos.push_back(new VinoEspecial(vino.nro, vino.cantidad_litros, vino.anio_produccion));
         }
        }
}


std::vector<Vino *> Gestor::cargarVinosDesdeArchivo(const std::string &archivo)
{
    std::ifstream archivo_binario(archivo, std::ios::binary);
    if (!archivo_binario.is_open()) {
        std::cout << "Error al abrir el archivo binario." << std::endl;
        return vinos;
    }

    regVino rVino;
    while (archivo_binario.read((char*)(&rVino), sizeof(regVino))) {

        if (rVino.tipo == 'M') {
            vinos.push_back(new VinoMesa(rVino.nro, rVino.cantidad_litros, rVino.anio_produccion));
        } else if (rVino.tipo == 'P') {
            vinos.push_back(new VinoPremium(rVino.nro, rVino.cantidad_litros, rVino.anio_produccion));
        } else if (rVino.tipo == 'E') {
            vinos.push_back(new VinoEspecial(rVino.nro, rVino.cantidad_litros, rVino.anio_produccion));
        }

    }
    archivo_binario.close();
    return vinos;
}

void Gestor::escribirInformeAnual(const std::vector<Vino*>& vinos, int anio) {

    std::string txtNom = "informe_" + std::to_string(anio) + ".txt";
    std::cout << "Va a escribir considerando "<< vinos.size() << " el Arch: " << txtNom << std::endl;

    std::ofstream output(txtNom);
    if (!output.is_open()) {
        std::cout << "Error al abrir el archivo de salida." << std::endl;
        return;
    }
    output << "Año\tLitros\tMonto" << std::endl;
    double montoTotal = 0.0;
    for (const auto& vino : vinos) {
        int litros = vino->getLtsVenta(anio);
        double monto = vino->getMntVenta(anio);
        montoTotal += monto;
        std::cout << anio << "\t" << litros << "\t" << monto << std::endl;
        output << anio << "\t" << litros << "\t" << monto << std::endl;
    }
    output << "Total\t\t" << montoTotal << std::endl;
    output.close();
}

std::vector<Vino *> Gestor::getVinos()
{
    return this->vinos;
}

int Gestor::getSize()
{
    return this->vinos.size();
}

Gestor::~Gestor() {
    for (auto vino : vinos) {
        delete vino;
    }
}

// 1. Los 5 años que se produjeron más litros
void Gestor::obtenerTop5AniosProduccion() {
    std::map<int, int> aniosProduccion; // Mapa para almacenar año y litros producidos

    for (const auto& vino : vinos) {
        for (int anio = 2020; anio <= 2025; ++anio) { // Suponiendo un rango de años
            aniosProduccion[anio] += vino->getLtsVenta(anio);
        }
    }

    // Ordenar años por litros producidos
    std::vector<std::pair<int, int>> aniosOrdenados(aniosProduccion.begin(), aniosProduccion.end());
    std::sort(aniosOrdenados.begin(), aniosOrdenados.end(), [](const auto& a, const auto& b) {
        return a.second > b.second; // Ordenar de mayor a menor
    });

    std::cout << "Top 5 años con más litros producidos:\n";
    for (int i = 0; i < 5 && i < aniosOrdenados.size(); ++i) {
        std::cout << "Año: " << aniosOrdenados[i].first << ", Litros: " << aniosOrdenados[i].second << std::endl;
    }
}

// 2. El año que se podrá vender más vino
int Gestor::anioMayorVenta() {
    int mejorAnio = 0;
    int maxLitros = 0;

    for (const auto& vino : vinos) {
        for (int anio = 2020; anio <= 2025; ++anio) {
            int litros = vino->getLtsVenta(anio);
            if (litros > maxLitros) {
                maxLitros = litros;
                mejorAnio = anio;
            }
        }
    }
    return mejorAnio;
}

// 3. El año que se podrá obtener mayor monto de venta
int Gestor::anioMayorMonto() {
    int mejorAnio = 0;
    double maxMonto = 0.0;

    for (const auto& vino : vinos) {
        for (int anio = 2000; anio <= 2025; ++anio) {
            double monto = vino->getMntVenta(anio);
            if (monto > maxMonto) {
                maxMonto = monto;
                mejorAnio = anio;
            }
        }
    }
    return mejorAnio;
}
