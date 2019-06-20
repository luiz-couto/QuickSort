#include <memory>
#include "pilha.h"
#include "quicksort.h"

// Construtor
Pilha::Pilha(){

    this->head = new node;
    this->tail = new node;

    this->head->next = this->tail;
    this->tail->previous = this->head;

    this->lenght = 0;

}

// Destrutor
Pilha::~Pilha(){
    
}

// Empilha
void Pilha::Push(Item i){

    node *new_node = new node;
    new_node->item = i;

    new_node->next = this->tail;
    new_node->previous = this->tail->previous;

    this->tail->previous->next = new_node;
    this->tail->previous = new_node;

    this->lenght++;

}

// Desempilha
Item Pilha::Retira(){

    node *nod = this->tail->previous;
    node *previous_node = nod->previous;

    previous_node->next = this->tail;
    this->tail->previous = previous_node;

    Item i = nod->item;

    delete nod;

    this->lenght--;
    return i;

}

// Verifica se pilha está vazia
bool Pilha::is_empty(){
    return this->lenght == 0;
}