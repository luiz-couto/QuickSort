#ifndef PILHA_H
#define PILHA_H

#include <iostream>
#include <sstream>


using namespace std;

struct Item
{
  int ini;
  int end;

  Item() {}
  Item(int ini, int end)
  {
    this->ini = ini;
    this->end = end;
  }
};

struct node{

    Item item;
    node *next;
    node *previous;

};

class Pilha{

    private:
        node *head;
        node *tail;
        int lenght;
    
    public:
        Pilha();
        ~Pilha();
        void Push(Item i);
        Item Retira();
        bool is_empty();
};

#endif