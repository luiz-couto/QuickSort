//QUICKSORT - ATIVIDADE PRÁTICA Nº2 - ESTRUTURA DE DADOS
//NOME: LUIZ FELIPE COUTO GONTIJO

//PARA MELHOR EXPLICAÇÃO DO CÓDIGO, VEJA A DOCUMENTAÇÃO

#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <chrono> 

#include "quicksort.h"

using namespace std;
using namespace std::chrono;

void RandomArray(int *array,int n){
    int aux = 2*n;
    for (int i=0;i<n;i++){
        
        array[i] = rand() % aux;
        
        
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
    
    std::string var = argv[1];
    std::string tipo = argv[2];
    int tamanho = std::stoi(argv[3]);
    int p;
    
    if(argc == 5){
        p = 1;
    }else{
        p = 0;
    }
    
    
    //int n;
    int array[tamanho];
    
    
    auto start = std::chrono::high_resolution_clock::now();
    if(tipo == "Ale"){
        RandomArray(array,tamanho);
        //n = sizeof(array)/sizeof(array[0]);

    }
    else if(tipo == "OrdC"){
        ArrayCres(array,tamanho);
        //n = sizeof(array)/sizeof(array[0]);
    }
    else if(tipo == "OrdD"){
        ArrayDecres(array,tamanho);
        //n = sizeof(array)/sizeof(array[0]);
        
    }

    

    QuickSort q(array,tamanho,p);
    //q.Print();

    if(var == "QC"){
        q.qsort(0,tamanho-1);
    }
    else if(var == "QM3"){
        q.qsort_med_tres(0,tamanho-1);
    }
    else if(var == "QPE"){
        q.qsort_primeiro(0,tamanho-1);
    }
    else if(var == "QI1"){
        q.qsort_one_percent(0,tamanho-1);
    }
    else if(var == "QI5"){
        q.qsort_five_percent(0,tamanho-1);
    }
    else if(var == "QI10"){
        q.qsort_ten_percent(0,tamanho-1);
    }     

    std::cout << var << " " << tipo << " " << tamanho << " ";
    q.PrintComp();
    q.PrintMov();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start); 
    cout << duration.count();
    printf("\n");
    
    
    
    return 0; 
} 