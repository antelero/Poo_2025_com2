#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

class Item
{
private:
    int numero;
    char descripcion[200];

public:
    Item(int n, const char* d);
    const char *getDescripcion() const;
    int getNumero() const;

    virtual double getPrecio() const = 0 ;
};

#endif // ITEM_H
