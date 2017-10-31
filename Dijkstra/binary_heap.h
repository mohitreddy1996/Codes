//
// Created by mohit on 22/10/17.
//

#ifndef CP_BINARY_HEAP_H
#define CP_BINARY_HEAP_H

#include <bits/stdc++.h>

using namespace std;

void swap(int *x, int *y);

class MinHeap
{
    // first = vertex.
    // second = cost.
    pair<int, int> *harr;
    int capacity;
    int heap_size;

public:
    MinHeap(int capacity);

    void MinHeapify(int );

    int parent(int i) { return (i-1)/2; }

    int left(int i) { return (2*i + 1); }

    int right(int i) { return (2*i + 2); }

    pair<int, int> extractMin();

    void decreaseKey(int i, int new_val);

    pair<int, int> getMin() { return harr[0]; }

    void deleteKey(int i);

    void insertKey(pair<int, int> k);

    bool isEmpty() {
        return heap_size == 0;
    }
};

#endif //CP_BINARY_HEAP_H
