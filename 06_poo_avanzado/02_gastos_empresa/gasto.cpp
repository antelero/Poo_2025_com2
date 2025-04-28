#include "gasto.h"
#include <iostream>

Gasto::Gasto()
{
    this->importe = 0;
}

double Gasto::getImporte()
{
    return  this->importe;
}

void Gasto::setImporte(double importe_){
    this->importe = importe_;
};



