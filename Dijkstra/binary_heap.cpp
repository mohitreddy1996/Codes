//
// Created by mohit on 22/10/17.
//

#include "binary_heap.h"

namespace {

    void swap(pair<int, int> *x, pair<int, int> *y)
    {
        pair<int, int> temp = *x;
        *x = *y;
        *y = temp;
    }
}

MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new pair<int, int>[cap];
}

void MinHeap::insertKey(pair<int, int> k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)].second > harr[i].second)
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i].second = new_val;
    while (i != 0 && harr[parent(i)].second > harr[i].second)
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

pair<int, int> MinHeap::extractMin()
{
    if (heap_size <= 0)
        return make_pair(INT_MAX, INT_MAX);
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }

    pair<int, int> root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);
    return root;
}

void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l].second < harr[i].second)
        smallest = l;
    if (r < heap_size && harr[r].second < harr[smallest].second)
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}
