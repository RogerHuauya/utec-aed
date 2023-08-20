#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 1e6+10;

class Ordenamiento{
private:
    int sz;
    ll array[MAX];
    
    void llenar(){
        random_device rd;
        uniform_int_distribution<int> dist(1,100);
        for(int i = 0;i < sz; i++)
            array[i] = dist(rd);  
    }

    int partition(int l, int r){
        int pivot = array[l];
        int aux = r;
        for(int i = r; i > l; i--){
            if(array[i] > pivot)
                swap(array[i],array[aux--]);
        }
        swap(array[l],array[aux]);
        return aux;
    }

public:
    Ordenamiento(int n){
        sz = n;
        llenar();
    }

    void quicksort(int l,int r){
        if(l<r){
            int p = partition(l,r);
            quicksort(l,p-1);
            quicksort(p+1,r);
        }
    }

    void merge_sort(){
        
    }

    void insertion_sort(){
        for (int i = 1; i < sz; i++){
            int j = i-1, cur = array[i];

            while(j >= 0 && array[j] > cur){
                array[j+1] = array[j];
                j--;
            }
            array[j+1] = cur;
        }
        
    }

    void print(){
        for(int i = 0; i < sz; i++) cout << array[i] << " ";
        cout << endl;
    }
};
