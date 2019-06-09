#include <iostream>
#include <sstream>

using namespace std;


class QuickSort{

    private:

        int *array;
        int number_of_elements;
    
    public:

        QuickSort(int array[],int n);
        ~QuickSort();
        void swap(int* a, int* b);
        void qsort(int left_index, int right_index);
        void qsort_med_tres(int left_index, int right_index);
        int partition(int i, int j);
        void Print();



};