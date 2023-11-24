#include "sorting.h"

using namespace std;

void global_benchmark();

int main(){
    global_benchmark();
    return 0;
}

void global_benchmark(){
    vector<int> cases = {10, 100, 1000, 10000, 100000, 1000000};
    QuickSort<int> quicksort(10);
    MergeSort<int> merge_sort(10);
    InsertionSort<int> insertion_sort(10);

    quicksort.create_csv();
    merge_sort.create_csv();
    insertion_sort.create_csv();

    for(auto n : cases){
        quicksort.set_sz(n);
        merge_sort.set_sz(n);
        insertion_sort.set_sz(n);

        quicksort.random_population();
        merge_sort.random_population();
        insertion_sort.random_population();

        quicksort.benchmark();
        merge_sort.benchmark();
        insertion_sort.benchmark();
    }
}
