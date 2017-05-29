//
// Created by Administrator on 2017/5/28.
//

#ifndef BINARYHEAP_BINARYHEAP_H
#define BINARYHEAP_BINARYHEAP_H

#include <vector>
using std::vector;
template < typename T>
class BinaryHeap {
public:
    BinaryHeap (int capacity = 100) ;
    BinaryHeap (vector<T> &item) ;
    ~BinaryHeap(){}
    bool isEmpty ();
    const T & findMin () const;
    void insert (const T & x);
    void deleteMin ();
    void deleteMin (T & minItem);
    void makeEmpty ();
    void showHeap();
private:
    int currentSize;
    vector<T> array;
    void percolateDown (int hole);
    void buildHeap ();
};
#endif //BINARYHEAP_BINARYHEAP_H
