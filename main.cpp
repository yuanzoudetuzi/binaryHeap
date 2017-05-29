#include <iostream>
using namespace std;
#include "BinaryHeap.h"
#include "BinaryHeap.cpp"


int main() {
    vector<int> vector1 = {3,5,6,7,2,10,1,4};
    BinaryHeap<int> BHeap(vector1);
    cout << "The binary heap is:" << endl;
    BHeap.showHeap();
    int min;
    cout << "The result of ascending order:" << endl;
    for (int i = 0; i < vector1.size(); i++) {
        BHeap.deleteMin(min);
        cout << min << " ";
    }
    cout << endl;
    return 0;
}

