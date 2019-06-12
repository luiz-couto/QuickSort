#ifndef PILHA_H
#define PILHA_H

#include <iostream>
#include <sstream>

using namespace std;

struct node{

    int value;
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
        void Push(int value);
        int Retira();
        bool is_empty();
};

#endif