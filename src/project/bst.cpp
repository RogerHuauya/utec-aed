#include <iostream>
#include <set>
#include <chrono>

#include "random_generator.h"

using namespace std;



int main() {
    for (int i = 1000; i <= 1000000; i*=10) {

        cout << "N: " << i << endl;
        vector<int> arr = generateUniqueRandomNumbers(1, 10000005, i + 1);


        multiset<int> s;
        for (int j = 0; j < i; j++)
            s.insert(arr[i]);


        //Start timer
        auto start = chrono::high_resolution_clock::now();
        //Porbar insertar
        s.insert(arr[i]);
        //End timer
        auto finish = chrono::high_resolution_clock::now();


        //Set in microseconds
        chrono::duration<double, std::micro> elapsed = finish - start;
        cout << "Insertar: " << elapsed.count() << " us" << endl;



        //Start timer
        start = chrono::high_resolution_clock::now();
        //Porbar buscar
        s.find(arr[i]);
        //End timer
        finish = chrono::high_resolution_clock::now();


        elapsed = finish - start;
        cout << "Buscar: " << elapsed.count() << " us" << endl;




        //Start timer
        start = chrono::high_resolution_clock::now();
        //Porbar borrar
        s.erase(arr[i]);
        //End timer
        finish = chrono::high_resolution_clock::now();


        elapsed = finish - start;
        cout << "Borrar: " << elapsed.count() << " us" << endl;
    }
    return 0;
}
