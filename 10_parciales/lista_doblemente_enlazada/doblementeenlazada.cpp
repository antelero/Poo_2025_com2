#include "doblementeenlazada.h"

DoblementeEnlazada::DoblementeEnlazada() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

// a. Saber cuántos elementos tiene.
int DoblementeEnlazada::getSize() {
    return this->size;
}

// b. Agregar un elemento.
void DoblementeEnlazada::addElemento(int value) {
    Nodo* newNode = new Nodo(value);
    if (this->head == nullptr) {
        this->head = newNode;
        this->tail = newNode;
    } else {
        this->tail->next = newNode;
        newNode->prev = this->tail;
        this->tail = newNode;
    }
    this->size++;
}

// c. Imprimir la lista del primero al último.
    void DoblementeEnlazada::impPrimeroUltimo() {
        Nodo* current = this->head;
        while (current != nullptr) {
            std::cout << current->dato << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // d. Imprimir la lista del último al primero.
    void DoblementeEnlazada::impUltimoPrimero() {
        Nodo* current = this->tail;
        while (current != nullptr) {
            std::cout << current->dato << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }


