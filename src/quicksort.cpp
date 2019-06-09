#include "quicksort.h"
#include <iostream>
#include <sstream>

QuickSort::QuickSort(int array[],int n){

    this->number_of_elements = n;
    this->array = new int[n];
    int i;
    for(i=0;i<n;i++){
        this->array[i] = array[i];
    }
    
}

QuickSort::~QuickSort(){

}

void QuickSort::swap(int *a,int *b){

    int t = *a; 
    *a = *b; 
    *b = t; 
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
        while(this->array[j] > pivot)
            j--;
        if(i <= j){
            this->swap(&this->array[i],&this->array[j]);
            i++;
            j--;
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
        while(this->array[j] > pivot)
            j--;
        if(i <= j){
            this->swap(&this->array[i],&this->array[j]);
            i++;
            j--;
            this->Print();
        }
        
    }

    qsort_med_tres(left_index,j);
    qsort_med_tres(i,right_index);

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
        while(this->array[j] > pivot)
            j--;
        if(i <= j){
            this->swap(&this->array[i],&this->array[j]);
            i++;
            j--;
            this->Print();
        }
        
    }

    qsort_primeiro(left_index,j);
    qsort_primeiro(i,right_index);

}

void QuickSort::Print(){
    int i;
    //this->swap(&this->array[0],&this->array[3]);
    for(i=0;i<this->number_of_elements;i++){

        printf("%i, ",this->array[i]);

    }
    printf("\n");
}