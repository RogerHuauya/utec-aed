#include <bits/stdc++.h>
#include "ordenamiento.h"
#define ll long long 
using namespace std;

int main(){
    ll n;
    cin >> n;

    Ordenamiento ord(n);
    ord.insertion_sort();
    ord.print();
    
    return 0;
}