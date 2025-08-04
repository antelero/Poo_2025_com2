#include "doblementeenlazada.h"

template <typename T>
DoblementeEnlazada<T>::DoblementeEnlazada(){
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

// a. Saber cuántos elementos tiene.
template <typename T>
int DoblementeEnlazada<T>::getSize() {
    return this->size;
}

// b. Agregar un elemento.
template <typename T>
void DoblementeEnlazada<T>::addElemento(T value) {
    Nodo<T>* newNode = new Nodo<T>(value);
    if (this->head == nullptr) {
        this->head = newNode;
        this->tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = this->tail;
        this->tail = newNode;
    }
    size++;
}

// c. Imprimir la lista del primero al último.
template <typename T>
void DoblementeEnlazada<T>::impPrimeroUltimo() {
        Nodo<T>* current = this->head;
        while (current != nullptr) {
            std::cout << current->dato << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

// d. Imprimir la lista del último al primero.
template <typename T>
void DoblementeEnlazada<T>::impUltimoPrimero() {
        Nodo<T>* current = this->tail;
        while (current != nullptr) {
            std::cout << current->dato << " ";
            current = current->prev;
        }
        std::cout << std::endl;

}


