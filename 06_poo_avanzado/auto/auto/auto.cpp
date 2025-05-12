#include "auto.h"

void Auto::arrancar() {
        motor->encender();
        for (int i = 0; i < 4; ++i) {
            ruedas[i]->rodar();
        }
    }

Auto::Auto(int hp, Rueda* r[])  {
    motor = new Motor(hp); // inicializarlo dentro del constructor
    for (int i = 0; i < 4; ++i) {
        ruedas[i] = r[i];
    }
}
