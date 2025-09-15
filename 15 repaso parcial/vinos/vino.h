#ifndef VINO_H
#define VINO_H
#include <iostream>
/*
Una empresa vitivinícola lo contrata para realizar un software que controle sus líneas de vinos, las cuales
son las siguientes :
    • de mesa : tiene un precio de 120 pesos por litro y está un año en barrica
    • premium: tiene un precio de 200 pesos por litro y está 2 años en barrica
    • especial: tiene un precio de 320 pesos por litro y está 2 años en barrica y 1 en botella.
La empresa guarda la información de su producción en un archivo binario, con el siguiente formato:
    nro : int
    Tipo : char //M(mesa), P (premium), E(especial)
    cantidad_litros: int
    anio_producción: int
*/

class Vino
{
protected:
    int nro;
    char tipo; //M(mesa), P (premium), E(especial)
    int cantidad_litros;
    int anio_produccion;

public:    
    Vino(int nro, char tipo, int cantidad_litros, int anio_produccion);

    virtual int getLtsVenta(int anio) = 0;
    virtual double getMntVenta(int anio) = 0;

    int getAnioProduccion()  {
        return anio_produccion;
    }

    char getTipo()  {
         return tipo;
    }

    // Declarar el operador<< como amigo
   //friend std::ostream& operator<<(std::ostream& os, const Vino& vino);

    virtual void imprimir(std::ostream& os) const;

    friend std::ostream &operator<<(std::ostream &os, const Vino &vino);
};

#endif // VINO_H
