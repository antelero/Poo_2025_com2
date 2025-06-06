#include <iostream>
#include "fraccion.h"

Fraccion::Fraccion(int nro)
{
    this->nro = nro;
    this->denominador = 1;
}

Fraccion::Fraccion(int nro, int denominador)
{
    int mcd = calcularMcd(nro, denominador);
    this->nro = nro/mcd;
    this->denominador = denominador/mcd;
}

/*Fraccion::Fraccion(Fraccion &f)
{
    this->nro = f.nro;
    this->denominador = f.denominador;
}*/

int Fraccion::calcularMcd(int nro, int denominador)
{
    int resto = nro % denominador;
    if (resto == 0) return denominador;
    return calcularMcd(denominador, resto);
}

Fraccion Fraccion::suma(Fraccion f)
{
    return Fraccion(f.nro * this->denominador + this->nro * f.denominador,
                    this->denominador * f.denominador);
}

Fraccion Fraccion::resta(Fraccion f)
{
    return Fraccion(this->nro * f.denominador - f.nro * this->denominador,
                    this->denominador * f.denominador);
}

Fraccion Fraccion::multiplicar(Fraccion f)
{
    return Fraccion(f.nro * this->nro,
                    this->denominador * f.denominador);
}

Fraccion Fraccion::dividir(Fraccion f)
{
    return Fraccion(f.denominador * this->nro,
                    this->denominador * f.nro);
}

Fraccion Fraccion::operator+(Fraccion other)
{
    return this->suma(other);
}

Fraccion Fraccion::operator-(Fraccion other)
{
    return this->resta(other);
   // return Fraccion(this->nro * other.denominador - other.nro * this->denominador,
   //                 this->denominador *other.denominador);
}

Fraccion Fraccion::operator*(Fraccion other)
{
    return this->multiplicar(other);
}

Fraccion Fraccion::operator/(Fraccion other)
{
    return this->dividir(other);
}

bool Fraccion::operator==(Fraccion other)
{
    return (this->nro / this->denominador) == (other.nro / other.denominador);
}

double Fraccion::mostrarFraccion()
{
   return ((double)this->nro / (double)this->denominador);
}

const std::string Fraccion::toString() {
    std::string s = std::to_string(this->nro);
    s.append("/");
    s.append(std::to_string(this->denominador));
    return s;
}

std::ostream& operator<<(std::ostream& os, const Fraccion& obj){
    os << obj.nro << "/" << obj.denominador;
    return os;
}
