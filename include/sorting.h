#pragma once

#include <random>
#include <chrono>
#include <iostream>

using namespace std;

template <typename T>
class Sort{
protected:
    int sz;
    T* arr;
    void random_population(){
        random_device rd;
        uniform_int_distribution<T> dist(1,100);
        for(int i = 0;i < sz; i++)
            arr[i] = dist(rd);
    }
public:
    Sort(int n){
        sz = n;
        arr = new T[sz];
        random_population();
    }
    virtual void sort() = 0;
    void benchmark(){
        auto start = chrono::steady_clock::now();
        sort();
        auto end = chrono::steady_clock::now();
        auto diff = end - start;
        std::cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
    }
};



template <typename T>
class QuickSort : public Sort<T>{
private:
    using Sort<T>::sz;
    using Sort<T>::arr;
    int partition(int l, int r){
        int pivot = arr[l];
        int aux = r;
        for(int i = r; i > l; i--){
            if(arr[i] > pivot)
                swap(arr[i],arr[aux--]);
        }
        swap(arr[l],arr[aux]);
        return aux;
    }
public:
    QuickSort(int n) : Sort<T>(n){}
    void sort(){
        sort(0,sz-1);
    }
    void sort(int l, int r){
        if(l<r){
            int p = partition(l,r);
            sort(l,p-1);
            sort(p+1,r);
        }
    }
};

template <typename T>
class MergeSort : public Sort<T>{
private:
    using Sort<T>::sz;
    using Sort<T>::arr;
public:
    MergeSort(int n) : Sort<T>(n){}
    void sort(){
        return;
    }
};

template <typename T>
class InsertionSort : public Sort<T>{
private:
    using Sort<T>::sz;
    using Sort<T>::arr;
public:
    InsertionSort(int n) : Sort<T>(n){}
    void sort(){
        for (int i = 1; i < sz; i++){
            int j = i-1, cur = arr[i];

            while(j >= 0 && arr[j] > cur){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = cur;
        }
    }
};
