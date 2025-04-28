#include "forma.h"
#include "iostream"
Forma::Forma()
{

}
std::ostream& operator<<(std::ostream& os, const Forma& obj){
    return os << "Bien : " ;
}
