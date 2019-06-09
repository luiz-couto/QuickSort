//QUICKSORT - ATIVIDADE PRÁTICA Nº2 - ESTRUTURA DE DADOS
//NOME: LUIZ FELIPE COUTO GONTIJO

//PARA MELHOR EXPLICAÇÃO DO CÓDIGO, VEJA A DOCUMENTAÇÃO

#include <iostream>
#include <sstream>
#include <stdio.h>

#include "quicksort.h"

using namespace std;
 
int main() 
{ 
    int array[] = {10, 7, 8, 9, 1, 5}; 
    int n = sizeof(array)/sizeof(array[0]);
   

    QuickSort q(array,n);
    q.Print();
    q.qsort(0,n-1);
    printf("----------------------------------\n");
    QuickSort q2(array,n);
    q2.Print();
    q2.qsort_primeiro(0,n-1);
    printf("----------------------------------\n");
    QuickSort q3(array,n);
    q3.Print();
    q3.qsort_med_tres(0,n-1);
    return 0; 
} 