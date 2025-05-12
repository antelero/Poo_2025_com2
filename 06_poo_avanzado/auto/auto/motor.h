#ifndef MOTOR_H
#define MOTOR_H


#include <iostream>
class Motor
{
private:
    int potencia;
public:
    Motor(int p);
    void encender() {
        std::cout << "Motor encendido con " << potencia << " HP\n";
    }
};

#endif // MOTOR_H
