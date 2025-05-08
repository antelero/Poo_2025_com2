#include <iostream>
#include "triangulo.h"
#include "rectangulo.h"
#include "forma.h"
#include "gestorformas.h"
#include "circulo.h"

using namespace std;

int main()
{
    Gestorformas* lis = new Gestorformas();
    int cant = 0;
    //cout << "-----------------------------" << endl;
    Triangulo *tri= new Triangulo();
    tri->setAlto(10);
    tri->setAncho(5);
    //cout << tri->area()<<endl;
    Rectangulo *rec= new Rectangulo();
    rec->setAlto(10);
    rec->setAncho(5);
    //cout << rec->area()<<endl;

    Circulo * cir = new Circulo();
    cir->setDiametro(10);
    //cout << cir->area()<<endl;
    lis->addForma(tri);
    lis->addForma(rec);
    lis->addForma(cir);
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
