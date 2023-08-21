#include "sorting.h"

using namespace std;

int main(){

    QuickSort<int> quicksort(10);
    quicksort.sort();
    quicksort.benchmark();

    MergeSort<int> merge_sort(10);
    merge_sort.sort();
    merge_sort.benchmark();

    InsertionSort<int> insertion_sort(10);
    insertion_sort.sort();
    insertion_sort.benchmark();

    return 0;
}
