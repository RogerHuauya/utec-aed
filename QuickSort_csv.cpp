#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "ordenamiento.h"

using namespace std;

int main(){
    ofstream myfile;
    myfile.open ("QuickSort_times.csv");
    myfile << "n,tiempo\n";
    for(int i = 1000; i <= 100000; i+=1000){
        Ordenamiento ord(i);
        auto start = chrono::steady_clock::now();
        ord.quicksort();
        auto end = chrono::steady_clock::now();
        auto diff = end - start;
        myfile << i << "," << chrono::duration <double, milli> (diff).count() << "\n";
    }
    myfile.close();
    return 0;
}