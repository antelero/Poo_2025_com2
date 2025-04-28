#include <iostream>
#include <gasto.h>
#include <gasto_compra.h>
#include <gasto_extraordinario.h>
#include <gasto_servicio.h>
#include <gestorgasto.h>
using namespace std;

int main()
{

    gestorgasto* lis = new gestorgasto();

    //Gastos de compras
    Gasto_Compra *gc= new Gasto_Compra("limpieza");
    gc->setImporte(1500);
    Gasto_Compra *gc1= new Gasto_Compra(" orden");
    gc1->setImporte(700);

    //Gastos de extraordinarios
    Gasto_Extraordinario *gce1= new Gasto_Extraordinario("Medialunas para la reunion");
    gce1->setImporte(100);
    Gasto_Extraordinario *gce= new Gasto_Extraordinario("focos");
    gce->setImporte(500);

    //Gastos de servicios
    Gasto_Servicio *gs1=new Gasto_Servicio("ServiLimp");
    gs1->setImporte(2500);
    Gasto_Servicio *gs=new Gasto_Servicio("Cerrajeria La Llave");
    gs->setImporte(100);

    //Agrego gastos al Gestor
    lis->addGasto(gc);
    lis->addGasto(gc1);
    lis->addGasto(gce1);
    lis->addGasto(gs1);
    lis->addGasto(gce);
    lis->addGasto(gs);

    //Obtengo la cantidad de elemntos
    int cantidad = lis->getCantidad();

    //Puntero de la clase padre - abstracta
    Gasto * gPtr;

    char orden = 'a';
    for(int i=0;i<cantidad;i++){
/*
        cout<< orden <<")Acc Lista " <<  i << " - " << lis->getGasto(i)->getDescripcion()<< ".............$" <<  lis->getGasto(i)->getImporte()<< endl;*/
        gPtr = lis->getGasto(i);
        cout<< orden <<")Obj padre " << i << " - " << (gPtr->getDescripcion())<< ".............$" << gPtr->getImporte()<< endl;
        orden++;
     };
    return 0;
}
