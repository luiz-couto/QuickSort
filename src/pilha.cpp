#include <memory>
#include "pilha.h"

Pilha::Pilha(){

    this->head = new node;
    this->tail = new node;

    this->head->next = this->tail;
    this->tail->previous = this->head;

    this->lenght = 0;

}

void Pilha::Push(int value){

    node *new_node = new node;
    new_node->value = value;

    new_node->next = this->tail;
    new_node->previous = this->tail->previous;

    this->tail->previous->next = new_node;
    this->tail->previous = new_node;

    this->lenght++;

}
int Pilha::Retira(){

    node *nod = this->tail->previous;
    node *previous_node = nod->previous;

    previous_node->next = this->tail;
    this->tail->previous = previous_node;

    int value = nod->value;

    delete nod;

    this->lenght--;
    return value;

}

bool Pilha::is_empty(){
    return this->lenght == 0;
}