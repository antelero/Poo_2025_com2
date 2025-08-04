#ifndef NODO_H
#define NODO_H


template <class T>
class Nodo
{
private:
public:
    T dato;
    Nodo();
    Nodo(T value);
    Nodo* next;
    Nodo* prev;
};

#endif // NODO_H
