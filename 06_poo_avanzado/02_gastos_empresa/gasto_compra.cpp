#include "gasto_compra.h"

Gasto_Compra::Gasto_Compra( std::string descrProducto)
{
    this->descrProducto=descrProducto;
}

 std::string Gasto_Compra::getDescripcion()
{
    return "Gasto por compra de productos de/para " + this->descrProducto;
}
