#ifndef GESTORFORMAS_H
#define GESTORFORMAS_H
#include "forma.h"



class Gestorformas
{
private:
    int cantidad = 0;
    Forma ** formas = 0;

public:
    int getCantidad();
    Forma* getObjeto(int);

    void addForma(Forma * form);

    Gestorformas();
};

#endif // GESTORFORMAS_H
