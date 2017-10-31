//
// Created by mohit on 30/10/17.
//

#ifndef CP_BINOMIAL_HEAP_H_H
#define CP_BINOMIAL_HEAP_H_H

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    pair<int, int> data;
    int degree;
    Node *child, *sibling, *parent;
    Node (pair<int, int> key) {
        data = key;
        degree = 0;
        child = parent = sibling = NULL;
    }
};

class BinomialHeap {
private:
    list<Node *> binomial_heap;
    Node* mergeBinomialTrees(Node *b1, Node *b2);
    list<Node*> unionBinomialHeap(list<Node*> l1, list<Node*> l2);
    void adjust();
    void insertATreeInHeap(Node *tree);
    list<Node*> removeMinFromTreeReturnBHeap(Node *tree);
    void printTree(Node *h);
    int numberOfNode;
public:
    void insert(pair<int, int> key);
    Node* getMin();
    void extractMin();
    void printHeap();
    bool isEmpty() {
        if (numberOfNode > 0) {
            return false;
        }
        return true;
    }
    BinomialHeap() {
        numberOfNode = 0;
    }
};

#endif //CP_BINOMIAL_HEAP_H_H
