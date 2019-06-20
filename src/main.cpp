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

// Gera array aleatório
void RandomArray(int *array, int n)
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(1, n);

  for (int i = 0; i < n; i++)
    array[i] = dis(gen);
}

// Gera array crescente
void ArrayCres(int *array, int n){
    
    for (int i=0;i<n;i++){
        array[i] = i;
    }
}

// Gera array decrescente
void ArrayDecres(int *array, int n){
    
    int j = 0;
    for (int i=n-1;i>=0;i--){
        array[j] = i;
        j++;
        
    }

}

// Troca dois elementos de um vetor do tipo long int
void swap_M(unsigned long long *a,unsigned long long *b){

    int t = *a; 
    *a = *b; 
    *b = t;
}

// Troca dois elementos de um vetor do tipo <time>
void swap_Time(std::chrono::duration<long, std::micro> *a,std::chrono::duration<long, std::micro> *b){

    std::chrono::duration<long, std::micro> t = *a; 
    *a = *b; 
    *b = t;
}

// Ordena vetor de inteiros (usado para achar a mediana)
void Ordenar_M(unsigned long long *array,int left_index, int right_index){

    
    int i,j,pivot;
    if(left_index >= right_index)
        return;
    i = left_index;
    j = right_index;

    pivot = array[(left_index+right_index)/2];
    //partition
    while(i<=j){
        while(array[i] < pivot)
            i++;
        while(array[j] > pivot)
            j--;
        if(i <= j){
            swap_M(&array[i],&array[j]);
            i++;
            j--;
        }
    }

    Ordenar_M(array,left_index,j);
    Ordenar_M(array,i,right_index);

}

// Ordena vetor do tipo <time> (usado para achar a mediana)
std::chrono::duration<long, std::micro> Ordenar_Time(std::chrono::duration<long, std::micro> *array, int left_index,int right_index)
{
    int i,j;
    std::chrono::duration<long, std::micro> pivot;
    if(left_index >= right_index){
        return array[11];
    }
    i = left_index;
    j = right_index;

    pivot = array[(left_index+right_index)/2];
    //partition
    while(i<=j){
        while(array[i] < pivot)
            i++;
        while(array[j] > pivot)
            j--;
        if(i <= j){
            swap_Time(&array[i],&array[j]);
            i++;
            j--;
        }
    }

    Ordenar_Time(array,left_index,j);
    Ordenar_Time(array,i,right_index);
}

 
int main(int argc, char *argv[]) 
{ 
    
    srand ( time(NULL) );
    std::string var;
    std::string tipo;
    std::string _cal;
    int tamanho;
    int p = 0;
    
    // Gera 9 tabelas com todos os dados caso não passe nenhum parametro na linha de comando
    if(argc == 1){


       
        string v_var[7] = {"QC","QM3","QPE","QI1","QI5","QI10","QNR"};
        string v_tipo[3] = {"Ale","OrdC","OrdD"};
        string v_cal[3] = {"Mod","Comp","Time"};
        int v_tamanho[10] = {50000,100000,150000,200000,250000,300000,350000,400000,450000,500000};

        for(int z=0;z<3;z++){
            _cal = v_cal[z];
            for(int i=0;i<3;i++){
                tipo = v_tipo[i];
                cout << _cal << " - " << tipo << " " << endl;
                cout << "Nº de elementos" << " " << "QC" << " " << "QM3" << " " << "QPE" << " " << "QI1" << " " << "QI5" << " " << "QI10" << " " << "QNR\n";
                for(int j=0;j<10;j++){
                    tamanho = v_tamanho[j];
                    cout << tamanho << " ";
                    int array[tamanho];
                    for(int k=0;k<7;k++){
                        var = v_var[k];
                        unsigned long long m[21];
                        unsigned long long mediana;
                        std::chrono::duration<long, std::micro> ex[21];
                        std::chrono::duration<long, std::micro> median_time;
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

                            auto start = std::chrono::high_resolution_clock::now();
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

                            if(_cal == "Comp")
                                m[l] = q.get_Comp();
                            else if(_cal == "Mod")
                                m[l] = q.get_Mod();
                            else if(_cal == "Time"){
                                
                                auto stop = std::chrono::high_resolution_clock::now();
                                auto duration = duration_cast<microseconds>(stop - start);
                                ex[l] = duration;
                                
                            }
                                
                        }
                        if(_cal == "Comp" || _cal == "Mod"){
                            Ordenar_M(m,0,20);
                            mediana = m[11];
                            cout << mediana << " ";
                        }
                        else{
                            median_time = Ordenar_Time(ex,0,20);
                            cout << median_time.count() << " ";
                        }

                    }

                    cout << "\n";
                }

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