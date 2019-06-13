#include "quicksort.h"
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include "pilha.h" 

QuickSort::QuickSort(int array[],int n,int p){

    this->n_de_comp = 0;
    this->n_de_movim = 0;
    this->number_of_elements = n;
    this->array = new int[n];
    this->p = p;
    int i;
    for(i=0;i<n;i++){
        this->array[i] = array[i];
    }
    
}

QuickSort::~QuickSort(){

    delete [] this->array;
}

void QuickSort::swap(int *a,int *b){

    int t = *a; 
    *a = *b; 
    *b = t;
    this->n_de_movim++; 
}

void QuickSort::qsort(int left_index, int right_index){

    
    int i,j,pivot;
    if(left_index >= right_index)
        return;
    i = left_index;
    j = right_index;

    pivot = this->array[(left_index+right_index)/2];
    //partition
    while(i<=j){
        while(this->array[i] < pivot)
            i++;
            this->n_de_comp++;
        while(this->array[j] > pivot)
            j--;
            this->n_de_comp++;
        if(i <= j){
            this->swap(&this->array[i],&this->array[j]);
            i++;
            j--;
            if(this->p == true)
                this->Print();
        }
        
    }

    qsort(left_index,j);
    qsort(i,right_index);

}

void QuickSort::qsort_med_tres(int left_index, int right_index){

    int i,j,pivot;
    if(left_index >= right_index)
        return;
    i = left_index;
    j = right_index;

    int number1 = this->array[left_index];
    int number2 = this->array[(left_index+right_index)/2];
    int number3 = this->array[(right_index)]; 

    if (number2 > number1 && number1 > number3 || number3 > number1 && number1 > number2)
        pivot = number1;
    else if (number1 > number2 && number2 > number3 || number3 > number2 && number2 > number1)
        pivot = number2;
    else if (number1 > number3 && number3 > number2 || number2 > number3 && number3 > number1)
        pivot = number3;
    else if(number1 == number2)
        pivot = number1;
    else if(number2 == number3)
        pivot = number2;
    else if(number1 == number3)
        pivot = number1;

    
    //partition
    while(i<=j){
        while(this->array[i] < pivot)
            i++;
            this->n_de_comp++;
        while(this->array[j] > pivot)
            j--;
            this->n_de_comp++;
        if(i <= j){
            this->swap(&this->array[i],&this->array[j]);
            i++;
            j--;
            if(this->p == true)
                this->Print();
        }
        
    }
    
    qsort_med_tres(left_index,j);
    qsort_med_tres(i,right_index);

}

void QuickSort::qsort_ten_percent(int left_index, int right_index){

    int i,j,pivot;
    if(left_index >= right_index)
        return;
    i = left_index;
    j = right_index;

    int number1 = this->array[left_index];
    int number2 = this->array[(left_index+right_index)/2];
    int number3 = this->array[(right_index)]; 

    if (number2 > number1 && number1 > number3 || number3 > number1 && number1 > number2)
        pivot = number1;
    else if (number1 > number2 && number2 > number3 || number3 > number2 && number2 > number1)
        pivot = number2;
    else if (number1 > number3 && number3 > number2 || number2 > number3 && number3 > number1)
        pivot = number3;
    else if(number1 == number2)
        pivot = number1;
    else if(number2 == number3)
        pivot = number2;
    else if(number1 == number3)
        pivot = number1;

    
    //partition
    while(i<=j){
        while(this->array[i] < pivot)
            i++;
            this->n_de_comp++;
        while(this->array[j] > pivot)
            j--;
            this->n_de_comp++;
        if(i <= j){
            this->swap(&this->array[i],&this->array[j]);
            i++;
            j--;
            if(this->p == true)
                this->Print();
        }
        
    }
    
    if(j-left_index+1 < this->number_of_elements/10){
        this->insertion_sort(left_index,j);
    }
        
    else{
        qsort_ten_percent(left_index,j);
    }

    
    if(right_index-i+1 < this->number_of_elements/10){
        this->insertion_sort(i,right_index);
    }
        
    else{
        qsort_ten_percent(i,right_index);
    }
        
    

}

void QuickSort::qsort_five_percent(int left_index, int right_index){

    int i,j,pivot;
    if(left_index >= right_index)
        return;
    i = left_index;
    j = right_index;

    int number1 = this->array[left_index];
    int number2 = this->array[(left_index+right_index)/2];
    int number3 = this->array[(right_index)]; 

    if (number2 > number1 && number1 > number3 || number3 > number1 && number1 > number2)
        pivot = number1;
    else if (number1 > number2 && number2 > number3 || number3 > number2 && number2 > number1)
        pivot = number2;
    else if (number1 > number3 && number3 > number2 || number2 > number3 && number3 > number1)
        pivot = number3;
    else if(number1 == number2)
        pivot = number1;
    else if(number2 == number3)
        pivot = number2;
    else if(number1 == number3)
        pivot = number1;

    
    //partition
    while(i<=j){
        while(this->array[i] < pivot)
            i++;
            this->n_de_comp++;
        while(this->array[j] > pivot)
            j--;
            this->n_de_comp++;
        if(i <= j){
            this->swap(&this->array[i],&this->array[j]);
            i++;
            j--;
            if(this->p == true)
                this->Print();
        }
        
    }
    
    if(j-left_index+1 < this->number_of_elements/20){
        this->insertion_sort(left_index,j);
    }
        
    else{
        qsort_five_percent(left_index,j);
    }

    
    if(right_index-i+1 < this->number_of_elements/20){
        this->insertion_sort(i,right_index);
    }
        
    else{
        qsort_five_percent(i,right_index);
    }
        
}

void QuickSort::qsort_one_percent(int left_index, int right_index){

    int i,j,pivot;
    if(left_index >= right_index)
        return;
    i = left_index;
    j = right_index;

    int number1 = this->array[left_index];
    int number2 = this->array[(left_index+right_index)/2];
    int number3 = this->array[(right_index)]; 

    if (number2 > number1 && number1 > number3 || number3 > number1 && number1 > number2)
        pivot = number1;
    else if (number1 > number2 && number2 > number3 || number3 > number2 && number2 > number1)
        pivot = number2;
    else if (number1 > number3 && number3 > number2 || number2 > number3 && number3 > number1)
        pivot = number3;
    else if(number1 == number2)
        pivot = number1;
    else if(number2 == number3)
        pivot = number2;
    else if(number1 == number3)
        pivot = number1;

    
    //partition
    while(i<=j){
        while(this->array[i] < pivot)
            i++;
            this->n_de_comp++;
        while(this->array[j] > pivot)
            j--;
            this->n_de_comp++;
        if(i <= j){
            this->swap(&this->array[i],&this->array[j]);
            i++;
            j--;
            if(this->p == true)
                this->Print();
        }
        
    }
    
    if(j-left_index+1 < this->number_of_elements/10){
        this->insertion_sort(left_index,j);
    }
        
    else{
        qsort_one_percent(left_index,j);
    }

    
    if(right_index-i+1 < this->number_of_elements/10){
        this->insertion_sort(i,right_index);
    }
        
    else{
        qsort_one_percent(i,right_index);
    }
        
    

}


void QuickSort::insertion_sort(int left_index,int right_index)
{
    if(left_index >= right_index)
        return;
    
    int i, j, tmp;
    
    for(i = left_index; i < right_index+1; i++)
    {
        tmp = this->array[i];
        for(j = i-1; j >= 0 && tmp < this->array[j]; j--)
        {   
            this->array[j+1] = this->array[j];
            this->n_de_comp++;
            
        }
        this->array[j+1] = tmp;
        this->n_de_movim++;
        if(this->p == true)
                this->Print();
        
    }
    
}

void QuickSort::qsort_primeiro(int left_index, int right_index){

    int i,j,pivot;
    if(left_index >= right_index)
        return;
    i = left_index;
    j = right_index;

    pivot = this->array[left_index];
                
    //partition
    while(i<=j){
        while(this->array[i] < pivot)
            i++;
            this->n_de_comp++;
        while(this->array[j] > pivot)
            j--;
            this->n_de_comp++;
        if(i <= j){
            this->swap(&this->array[i],&this->array[j]);
            i++;
            j--;
            if(this->p == true)
                this->Print();
        }
        
    }

    qsort_primeiro(left_index,j);
    qsort_primeiro(i,right_index);

}

void QuickSort::qsort_non_recursive(int ini, int end){

    int i,j,pivot;
    Pilha pilha = Pilha();
    pilha.Push(Item(ini,end));

    do
    {
        if(end > ini){
            i = ini;
            j = end;
            pivot = array[(ini + end) / 2];
            //partition
            while(i<=j){
                while(this->array[i] < pivot)
                    i++;
                    this->n_de_comp++;
                while(this->array[j] > pivot)
                    j--;
                    this->n_de_comp++;
                if(i <= j){
                    this->swap(&this->array[i],&this->array[j]);
                    i++;
                    j--;
                    if(this->p == true)
                        this->Print();
                }
        
            }
    
            if((j - ini) > (end - i)){
                pilha.Push(Item(ini,j));
                ini = i;
            }else{
                pilha.Push(Item(i,end));
                end = j;
            }
        }else{
            Item item = pilha.Retira();
            end = item.end;
            ini = item.ini;
        }


    } while (!pilha.is_empty());
    
  


}

void QuickSort::Print(){
    int i;
    //this->swap(&this->array[0],&this->array[3]);
    for(i=0;i<this->number_of_elements;i++){

        printf("%i, ",this->array[i]);

    }
    printf("\n");
}

void QuickSort::PrintComp(){
    printf("%i ",this->n_de_comp);
}

void QuickSort::PrintMov(){
    printf("%i ",this->n_de_movim);
}
int QuickSort::get_Comp(){
    return this->n_de_comp;
}
