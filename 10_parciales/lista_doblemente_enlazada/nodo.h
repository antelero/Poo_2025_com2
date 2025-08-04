#ifndef NODO_H
#define NODO_H


class Nodo
{
public:
    Nodo();

    int dato;
    Nodo* next;
    Nodo* prev;

    Nodo(int value);
};

#endif // NODO_H
