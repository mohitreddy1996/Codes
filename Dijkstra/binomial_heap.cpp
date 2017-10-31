//
// Created by mohit on 22/10/17.
//
#include<bits/stdc++.h>
#include "binomial_heap.h"
using namespace std;

Node* BinomialHeap::mergeBinomialTrees(Node *b1, Node *b2)
{
    if ((b1->data).second > (b2->data).second)
        swap(b1, b2);
    b2->parent = b1;
    b2->sibling = b1->child;
    b1->child = b2;
    b1->degree++;
    return b1;
}

list<Node*> BinomialHeap::unionBinomialHeap(list<Node*> l1, list<Node*> l2)
{
    list<Node*> _new;
    list<Node*>::iterator it = l1.begin();
    list<Node*>::iterator ot = l2.begin();
    while (it!=l1.end() && ot!=l2.end())
    {
        if((*it)->degree <= (*ot)->degree)
        {
            _new.push_back(*it);
            it++;
        }
        else
        {
            _new.push_back(*ot);
            ot++;
        }
    }

    while (it != l1.end())
    {
        _new.push_back(*it);
        it++;
    }

    while (ot!=l2.end())
    {
        _new.push_back(*ot);
        ot++;
    }
    return _new;
}

void BinomialHeap::adjust()
{
    if (binomial_heap.size() <= 1)
        return;
    list<Node*> new_heap;
    list<Node*>::iterator it1,it2,it3;
    it1 = it2 = it3 = binomial_heap.begin();

    if (binomial_heap.size() == 2)
    {
        it2 = it1;
        it2++;
        it3 = binomial_heap.end();
    }
    else
    {
        it2++;
        it3=it2;
        it3++;
    }
    while (it1 != binomial_heap.end())
    {
        if (it2 == binomial_heap.end())
            it1++;
        else if ((*it1)->degree < (*it2)->degree)
        {
            it1++;
            it2++;
            if(it3!=binomial_heap.end())
                it3++;
        }
        else if (it3 != binomial_heap.end() &&
                 (*it1)->degree == (*it2)->degree &&
                 (*it1)->degree == (*it3)->degree)
        {
            it1++;
            it2++;
            it3++;
        }
        else if ((*it1)->degree == (*it2)->degree)
        {
            Node *temp;
            *it1 = mergeBinomialTrees(*it1,*it2);
            it2 = binomial_heap.erase(it2);
            if(it3 != binomial_heap.end())
                it3++;
        }
    }
}

void BinomialHeap::insertATreeInHeap(Node *tree)
{
    list<Node*> temp;
    temp.push_back(tree);
    binomial_heap = unionBinomialHeap(binomial_heap, temp);
    adjust();
}

list<Node*> BinomialHeap::removeMinFromTreeReturnBHeap(Node *tree)
{
    list<Node*> heap;
    Node *temp = tree->child;
    Node *lo;

    while (temp)
    {
        lo = temp;
        temp = temp->sibling;
        lo->sibling = NULL;
        heap.push_front(lo);
    }
    return heap;
}

void BinomialHeap::printTree(Node *h)
{
    while (h)
    {
        cout << (h->data).first << " ";
        printTree(h->child);
        h = h->sibling;
    }
}

void BinomialHeap::insert(pair<int, int> key)
{
    Node *temp = new Node(key);
    numberOfNode++;
    insertATreeInHeap(temp);
}

Node* BinomialHeap::getMin()
{
    list<Node*>::iterator it = binomial_heap.begin();
    Node *temp = *it;
    while (it != binomial_heap.end())
    {
        if (((*it)->data).second < (temp->data).second)
            temp = *it;
        it++;
    }
    return temp;
}

void BinomialHeap::extractMin()
{
    list<Node*> new_heap,lo;
    Node *temp;
    numberOfNode--;
    // temp contains the pointer of minimum value
    // element in heap
    temp = getMin();
    list<Node*>::iterator it;
    it = binomial_heap.begin();
    while (it != binomial_heap.end())
    {
        if (*it != temp)
        {
            // inserting all Binomial Tree into new
            // binomial heap except the Binomial Tree
            // contains minimum element
            new_heap.push_back(*it);
        }
        it++;
    }
    lo = removeMinFromTreeReturnBHeap(temp);
    binomial_heap = unionBinomialHeap(new_heap, lo);
    adjust();
    return;
}

void BinomialHeap::printHeap()
{
    list<Node*> ::iterator it;
    it = binomial_heap.begin();
    while (it != binomial_heap.end())
    {
        printTree(*it);
        it++;
    }
}