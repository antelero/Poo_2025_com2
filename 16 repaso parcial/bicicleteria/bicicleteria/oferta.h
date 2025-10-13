#ifndef OFERTA_H
#define OFERTA_H
#include <vector>
#include <iostream>
#include "bicicleta.h"

class Oferta: public Item {
private:
    std::vector<Item*> items;
public:
    Oferta(int n, const char* d);
    void agregarItem(Item* np);
    double getPrecio() const;

    // Declare friend operator<< so it can access private members if needed
    friend std::ostream& operator<<(std::ostream& os, const Oferta& o);
};

#endif // OFERTA_H
