//
// Created by mohit on 22/10/17.
//

#ifndef CP_FIBONACCI_HEAP_H
#define CP_FIBONACCI_HEAP_H

#include <bits/stdc++.h>

using namespace std;

class node {

private:
    node* prev;
    node* next;
    node* child;
    node* parent;
    pair<int, int> value;
    int degree;
    bool marked;
public:
    friend class FibonacciHeap;
    node* getPrev() {return prev;}
    node* getNext() {return next;}
    node* getChild() {return child;}
    node* getParent() {return parent;}
    pair<int, int> getValue() {return value;}
    bool isMarked() {return marked;}

    bool hasChildren() {return child;}
    bool hasParent() {return parent;}
};

class FibonacciHeap {
protected:
    node* heap;
public:
    FibonacciHeap() {
        heap=_empty();
    }
    virtual ~FibonacciHeap() {
        if(heap) {
            _deleteAll(heap);
        }
    }
    node* insert(pair<int, int> value);

    void merge(FibonacciHeap& other);

    bool isEmpty();

    pair<int, int> getMinimum();

    pair<int, int> removeMinimum();

    void decreaseKey(node* n, int value);

    node* find(pair<int, int> value);
private:
    node* _empty();

    node* _singleton(pair<int, int> value);

    node* _merge(node* a, node* b);

    void _deleteAll(node* n);

    void _addChild(node* parent,node* child);

    void _unMarkAndUnParentAll(node* n);

    node* _removeMinimum(node* n);

    node* _cut(node* heap, node* n);

    node* _decreaseKey(node* heap, node* n, int value);

    node* _find(node* heap, pair<int, int> value);
};


#endif //CP_FIBONACCI_HEAP_H
