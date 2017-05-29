//
// Created by Administrator on 2017/5/28.
//
#include <iostream>
#include "BinaryHeap.h"

/*class UnderflowException { };*/
template<typename T>
BinaryHeap<T>::BinaryHeap(int capacity)
        : array(capacity+10), currentSize(capacity) {
}

template<typename T>
BinaryHeap<T>::BinaryHeap(vector<T> &item)
        : array(item.size() + 10), currentSize(item.size())
{
    for (int i = 0; i != item.size(); i++)
        array[i+1] = item[i];
    buildHeap();
}

template<typename T>
bool BinaryHeap<T>::isEmpty() {
    return array.size() == 0 ? true : false;
}

template<typename T>
void BinaryHeap<T>::makeEmpty() {
    if (isEmpty())
        return;
    for (auto size = array.size(); size > 0; size--) {
        array.pop_back();
    }
    currentSize = 0;
}

template <typename T>
void BinaryHeap<T>::showHeap() {
    for(int i = 1; i <= currentSize; i++ )
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

template<typename T>
void BinaryHeap<T>::insert(const T &x) {
    if (currentSize == array.size() - 1) {
        array.resize(array.size() * 2);
    }
    int hole = ++currentSize;
    /*将需要插入的值与当前树中的最后一个元素的父元素做比较，若父元素大于x,则将父元素移到当前子元素的位置
     * 直到父元素小与等于x,则x插入当前子元素的位置。
    */
    for (; hole > 1 && x < array[hole / 2]; hole /= 2) {
        array[hole] = array[hole / 2];
    }
    array[hole] = x;
}

template<typename T>
void BinaryHeap<T>::deleteMin() {
    if (isEmpty()) {
        std::cout << "The heap is empty!" << std::endl;
    }
    //将array中最后一个数赋值给第一个元素，array元素个数减一；然后开始下滤
    array[1] = array[currentSize--];
    percolateDown(1);
}

template<typename T>
void BinaryHeap<T>::deleteMin(T &minItem) {
    if (isEmpty()) {
        std::cout << "The heap is empty!" << std::endl;
    }
    minItem = array[1];
    //将array中最后一个数赋值给第一个元素，array元素个数减一；然后开始下滤
    array[1] = array[currentSize--];
    percolateDown(1);
}

template<typename T>
void BinaryHeap<T>::percolateDown(int hole) {
    T x = array[hole];
    int child;
    /*找出当前父元素的子元素中最小的一个child，然后和父元素比较，如果child小与父元素，
     则将child的值赋给父元素，直到父元素的值小与等于子元素的值，此时将x的值赋给这个父元素终止循环 */

    for (; hole * 2 <= currentSize; hole = child) {
        child = 2 * hole;
        if (child != currentSize && array[child + 1] < array[child])
            child++;
        if (array[child] < x)
            array[hole] = array[child];
        else
            break;
    }
    array[hole] = x;
}

template<typename T>
void BinaryHeap<T>::buildHeap() {
    for (int i = currentSize / 2; i > 0; i--)
        percolateDown(i);
}