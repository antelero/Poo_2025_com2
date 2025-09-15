#include <iostream>
#include <gestor.h>


using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    Gestor *ges = new Gestor();
    //ges->generarBinVinos();
    ges->cargarVinosDesdeArchivo("vinos.bin");

    //Levanto datos de prueba
   // ges->generarVinosDummy();

    cout << "Tamano " <<ges->getSize()<< std::endl;

    for (const auto& vino : ges->getVinos()) {
           std::cout << *vino << std::endl; // This will work now
    }

    // 1. Calcular la cantidad de litros y monto para un año determinado (por ejemplo, 2022)
    int anioDeseado = 2022;
    int litrosVendibles = 0;
    double montoTotal = 0.0;
    for (const auto& vino : ges->getVinos()) {
        litrosVendibles += vino->getLtsVenta(anioDeseado);
        montoTotal += vino->getMntVenta(anioDeseado);
    }
    cout << "Para el anio " << anioDeseado << ":" << endl;
    cout << "Cantidad de litros vendibles: " << litrosVendibles << " litros" << endl;
    cout << "Monto total obtenido: $" << montoTotal << endl;

    // 2. Escribir el informe anual para los años 2020 a 2023
    cout << "Va a escribir el informe por anio" << endl;
    for (int anio = 2020; anio <= 2023; ++anio) {
        cout << "anio " << anio <<endl;
        ges->escribirInformeAnual(ges->getVinos(), anio);
    }

    // 3.1. Los 5 años que se produjeron más litros
    ges->obtenerTop5AniosProduccion();

    // 3.2. El año que se podrá vender más vino
    cout << "El año que se podrá vender más vino " << ges->anioMayorVenta() <<endl;

    // 3.3. El año que se podrá obtener mayor monto de venta
    cout << "El año que se podrá obtener mayor monto de venta: " << ges->anioMayorVenta() <<endl;
    cout << "FIN" << endl;

    VinoEspecial vinoChar(888, 150, 2024);
    std::cout << vinoChar << std::endl; //
    return 0;
}
