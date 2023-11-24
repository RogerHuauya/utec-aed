#include "treap.h"
#include "random_generator.h"

int main() {
    for (int i = 1000; i <= 1000000; i*=10){
        vector<int> random_vector = generateUniqueRandomNumbers(1, 10000005, i + 1);
        Node* root = nullptr;
        for (int j = 0; j < i; j++)
            insert(root, random_vector[j]);

        auto start = chrono::steady_clock::now();
        insert(root, random_vector[i]);
        auto end = chrono::steady_clock::now();
        auto diff = end - start;
        std::cout << "Insertion of element in N: "<< i << " treap size,  Time: "<<chrono::duration <double, micro> (diff).count() << " us" << endl;

        start = chrono::steady_clock::now();
        search(root, 500);
        end = chrono::steady_clock::now();
        diff = end - start;
        std::cout << "Search of element in N: "<< i << " treap size Time: "<<chrono::duration <double, micro> (diff).count() << " us" << endl;

        start = chrono::steady_clock::now();
        Delete(root, 500);
        end = chrono::steady_clock::now();
        diff = end - start;
        std::cout << "Delete of element in N: "<< i << " treap size Time: "<<chrono::duration <double, micro> (diff).count() << " us" << endl;
        std::cout << "\n\n\n\n";
    }
    return 0;
}
