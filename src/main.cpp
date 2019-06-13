//QUICKSORT - ATIVIDADE PRÁTICA Nº2 - ESTRUTURA DE DADOS
//NOME: LUIZ FELIPE COUTO GONTIJO

//PARA MELHOR EXPLICAÇÃO DO CÓDIGO, VEJA A DOCUMENTAÇÃO

#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <chrono> 
#include <time.h>
#include <memory>
#include <stdexcept>
#include <random>


#include "quicksort.h"

using namespace std;
using namespace std::chrono;

void RandomArray(int *array, int n)
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(1, n);

  for (int i = 0; i < n; i++)
    array[i] = dis(gen);
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
    
    srand ( time(NULL) );
    std::string var;
    std::string tipo;
    int tamanho;
    int p = 0;
    
    if(argc == 1){

       
        string v_var[7] = {"QC","QM3","QPE","QI1","QI5","QI10","QNR"};
        string v_tipo[3] = {"Ale","OrdC","OrdD"};
        int v_tamanho[10] = {50000,100000,150000,200000,250000,300000,350000,400000,450000,500000};

        for(int i=0;i<3;i++){
            cout << "Nº de elementos" << " " << "QC" << " " << "QM3" << " " << "QPE" << " " << "QI1" << " " << "QI5" << " " << "QI10" << " " << "QNR\n";
            tipo = v_tipo[i];
            for(int j=0;j<10;j++){
                tamanho = v_tamanho[j];
                cout << tamanho << " ";
                int array[tamanho];
                for(int k=0;k<7;k++){
                    var = v_var[k];
                    int m[21];
                    int mediana;
                    for(int l=0;l<21;l++){
                    
                        if(tipo == "Ale"){
                            RandomArray(array,tamanho);
                        }
                        else if(tipo == "OrdC"){
                            ArrayCres(array,tamanho);
                        }
                        else if(tipo == "OrdD"){
                            ArrayDecres(array,tamanho);        
                        }

                        QuickSort q(array,tamanho,p);

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
                        else if(var == "QNR"){
                            q.qsort_non_recursive(0,tamanho-1);
                        }

                        m[l] = q.get_Comp();
                    }

                    QuickSort _m(m,21,0);
                    _m.qsort(0,20);
                    mediana = m[11];
                    cout << mediana << " ";
                }

                cout << "\n";
            }

        }


    }else{


        if(argc == 5){
            var = argv[1];
            tipo = argv[2];
            tamanho = std::stoi(argv[3]);
            p = 1;
        }else{
            var = argv[1];
            tipo = argv[2];
            tamanho = std::stoi(argv[3]);
            p = 0;
        }

        
        int array[tamanho];
       
        
        auto start = std::chrono::high_resolution_clock::now();
        if(tipo == "Ale"){
            RandomArray(array,tamanho);
        }
        else if(tipo == "OrdC"){
            ArrayCres(array,tamanho);
        }
        else if(tipo == "OrdD"){
            ArrayDecres(array,tamanho);        
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
        else if(var == "QNR"){
            q.qsort_non_recursive(0,tamanho-1);
        }     

        std::cout << var << " " << tipo << " " << tamanho << " ";
        q.PrintComp();
        q.PrintMov();
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start); 
        cout << duration.count();
        printf("\n");
    
    }
    
    return 0; 
} 