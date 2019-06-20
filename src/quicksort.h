#include <iostream>
#include <sstream>

using namespace std;


class QuickSort{

    private:

        int *array;
        int number_of_elements;
        unsigned long long n_de_comp;
        unsigned long long n_de_movim;
        bool p;
    
    public:

        QuickSort(int array[],int n, int p);
        ~QuickSort();
        void swap(int* a, int* b);
        void qsort(int left_index, int right_index);
        void qsort_med_tres(int left_index, int right_index);
        void qsort_primeiro(int left_index, int right_index);
        void insertion_sort(int left_index,int right_index);
        void qsort_ten_percent(int left_index, int right_index);
        void qsort_five_percent(int left_index, int right_index);
        void qsort_one_percent(int left_index, int right_index);
        void qsort_non_recursive(int left_index, int right_index);
        int partition(int i, int j);
        int get_Comp();
        int get_Mod();
        void Print();
        void PrintComp();
        void PrintMov();
        void PrintTime();



};