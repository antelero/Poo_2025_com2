#include "gasto_servicio.h"

Gasto_Servicio::Gasto_Servicio(std::string descrServ)
{
    this->descrServ=descrServ;

}


 std::string Gasto_Servicio::getDescripcion()
{
   return  "Gasto por  servicio de la empresa: "+this->descrServ;
}
