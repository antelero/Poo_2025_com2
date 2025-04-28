#include "gasto_extraordinario.h"

Gasto_Extraordinario::Gasto_Extraordinario(std::string descrExtra)
{
    this->descrExtra=descrExtra;

}
 std::string Gasto_Extraordinario::getDescripcion()
{
    return  "Gasto extraordinario "+ this->descrExtra;
}
