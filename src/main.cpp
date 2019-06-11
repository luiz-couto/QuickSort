//QUICKSORT - ATIVIDADE PRÁTICA Nº2 - ESTRUTURA DE DADOS
//NOME: LUIZ FELIPE COUTO GONTIJO

//PARA MELHOR EXPLICAÇÃO DO CÓDIGO, VEJA A DOCUMENTAÇÃO

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h> 

#include "quicksort.h"

using namespace std;

void RandomArray(int *array,int n){
    
    for (int i=0;i<n;i++){
        array[i] = rand() % 2*n;
    }

}

void ArrayCres(int *array, int n){
    
    for (int i=0;i<n;i++){
        array[i] = i;
    }
}

void ArrayDecres(int *array, int n){
    
    int j = 0;
    for (int i=n-1;i>=0;i--){
        array[j] = i;
        j++;
    }

}
 
int main(int argc, char *argv[]) 
{ 
    
    printf("%s %s %s %s\n",argv[1],argv[2],argv[3],argv[4]);
    bool p;
    
    if(argv[4] == "-p"){
        p = true;
    }else{
        p = false;
    }
    
    
    
    
    
    int array[10]; 
    ArrayDecres(array,10);
    int n = sizeof(array)/sizeof(array[0]);

    QuickSort q(array,n,p);
    if(p == true)
        q.Print();
    q.qsort(0,n-1);
    //printf("----------------------------------\n");
    QuickSort q2(array,n,p);
    if(p == true)
        q2.Print();
    q2.qsort_primeiro(0,n-1);
    //printf("----------------------------------\n");
    QuickSort q3(array,n,p);
    if(p == true)
        q3.Print();
    q3.qsort_med_tres(0,n-1);
    //printf("----------------------------------\n");
    QuickSort q4(array,n,p);
    if(p == true)
        q4.Print();
    //q4.qsort_ten_percent(0,n-1);
    return 0; 
} 