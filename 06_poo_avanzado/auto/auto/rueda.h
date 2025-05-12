#ifndef RUEDA_H
#define RUEDA_H


#include <iostream>
class Rueda
{
private:
    int diametro;
public:
    Rueda(int d);
    void rodar() {
        std::cout << "Rueda de " << diametro << " pulgadas rodando\n";
    }
};

#endif // RUEDA_H
