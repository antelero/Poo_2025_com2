#include <iostream>
#include "cuadrado.h"
#include "triangulo.h"
#include "rectangulo.h"
#include "forma.h"
#include "gestorformas.h"
#include "circulo.h"

using namespace std;

int main()
{
    cout << "-----------------------------" << endl;
    cout << "Crea Gestor" << endl;
    Gestorformas* lis = new Gestorformas();
    int cant = 0;
    cout << "Crea triangulo" << endl;
    Triangulo *tri= new Triangulo(10,5);
    //cout << tri->area()<<endl;
    cout << "Crea rectangulo" << endl;
    Rectangulo *rec= new Rectangulo(10,5);
    //cout << rec->area()<<endl;

    cout << "Crea Circulo" << endl;
    Circulo * cir = new Circulo(10);

    cout << "Crea Cuadrado" << endl;
    Cuadrado * cdo = new Cuadrado(10);

    //cout << cir->area()<<endl;
    cout << "Agrega formas al gestor" << endl;
    lis->addForma(tri);
    lis->addForma(rec);
    lis->addForma(cir);
    lis->addForma(cdo);
    cant = lis->getCantidad();
    Forma *frmPtr = 0;
    lis[0].getCantidad();
    for(int i=0;i<cant;i++){
        //cout <<  i << " " << lis->getObjeto(i)->area()<< endl;
        frmPtr = lis->getObjeto(i);
        cout<<  i << " - " << (frmPtr->area())<< endl;//area() <<endl;
     };
    return 0;
}
