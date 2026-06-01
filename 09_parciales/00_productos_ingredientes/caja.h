#ifndef CAJA_H
#define CAJA_H


template <typename T>
class Caja {
    T contenido;
public:
    Caja(T v);
    T get() const;
};



#endif // CAJA_H
