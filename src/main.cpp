//QUICKSORT - ATIVIDADE PRÁTICA Nº2 - ESTRUTURA DE DADOS
//NOME: LUIZ FELIPE COUTO GONTIJO

//PARA MELHOR EXPLICAÇÃO DO CÓDIGO, VEJA A DOCUMENTAÇÃO

#include <iostream>
#include <sstream>
#include <stdio.h>

#include "quicksort.h"

using namespace std;

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition (int array[], int primeiro, int ultimo) 
{ 
    int pivot = array[ultimo];    // pivot 
    int i = (primeiro - 1);  // Index of smaller element 
  
    for (int j = primeiro; j <= ultimo-1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (array[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&array[i], &array[j]); 
        } 
    } 
    swap(&array[i + 1], &array[ultimo]); 
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void quickSort(int array[], int primeiro, int ultimo) 
{ 
    if (primeiro < ultimo) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int p = partition(array, primeiro, ultimo); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(array, primeiro, p - 1); 
        quickSort(array, p + 1, ultimo); 
    } 
} 

void printArray(int array[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", array[i]); 
    printf("n"); 
} 
  
// Driver program to test above functions 
int main() 
{ 
    int array[] = {10, 7, 8, 9, 1, 5}; 
    int n = sizeof(array)/sizeof(array[0]);
    // printf("%i\n\n",n); 
    // quickSort(array, 0, n-1); 
    // printf("Sorted array: n"); 
    // printArray(array, n);

    QuickSort q(array,n);
    q.Print();
    q.qsort(0,n-1);
    printf("----------------------------------\n");
    QuickSort q2(array,n);
    q2.Print();
    q2.qsort_med_tres(0,n-1);
    // q2.Print();
    return 0; 
} 