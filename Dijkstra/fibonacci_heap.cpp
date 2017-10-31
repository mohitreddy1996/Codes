//
// Created by mohit on 22/10/17.
//

#include "fibonacci_heap.h"

node* FibonacciHeap::insert(pair<int, int> value) {
    node* ret = _singleton(value);
    heap = _merge(heap,ret);
    return ret;
}

void FibonacciHeap::merge(FibonacciHeap& other) {
    heap = _merge(heap, other.heap);
    other.heap = _empty();
}

bool FibonacciHeap::isEmpty() {
    return heap == NULL;
}

pair<int, int> FibonacciHeap::getMinimum() {
    return heap->value;
}

pair<int, int> FibonacciHeap::removeMinimum() {
    node* old = heap;
    heap = _removeMinimum(heap);
    pair<int, int> ret = old->value;
    delete old;
    return ret;
}

void FibonacciHeap::decreaseKey(node* n, int value) {
    heap = _decreaseKey(heap, n, value);
}

node* FibonacciHeap::find(pair<int, int> value) {
    return _find(heap, value);
}

node* FibonacciHeap::_empty() {
    return NULL;
}

node* FibonacciHeap::_singleton(pair<int, int> value) {
    node* n = new node();
    n->value=value;
    n->prev=n->next=n;
    n->degree=0;
    n->marked=false;
    n->child=NULL;
    n->parent=NULL;
    return n;
}

node* FibonacciHeap::_merge(node* a, node* b) {
    if(a==NULL)return b;
    if(b==NULL)return a;
    if((a->value).second > (b->value).second) {
        node* temp=a;
        a=b;
        b=temp;
    }
    node* an=a->next;
    node* bp=b->prev;
    a->next=b;
    b->prev=a;
    an->prev=bp;
    bp->next=an;
    return a;
}

void FibonacciHeap::_deleteAll(node* n) {
    if(n != NULL) {
        node* c = n;
        do {
            node* d = c;
            c = c->next;
            _deleteAll(d->child);
            delete d;
        } while(c != n);
    }
}

void FibonacciHeap::_addChild(node* parent,node* child) {
    child->prev = child->next = child;
    child->parent = parent;
    parent->degree++;
    parent->child = _merge(parent->child, child);
}

void FibonacciHeap::_unMarkAndUnParentAll(node* n) {
    if(n==NULL)return;
    node* c=n;
    do {
        c->marked = false;
        c->parent = NULL;
        c = c->next;
    } while(c != n);
}

node* FibonacciHeap::_removeMinimum(node* n) {
    _unMarkAndUnParentAll(n->child);
    if(n->next==n) {
        n=n->child;
    } else {
        n->next->prev=n->prev;
        n->prev->next=n->next;
        n=_merge(n->next,n->child);
    }
    if(n==NULL)return n;
    node* trees[64]={NULL};

    while(true) {
        if(trees[n->degree]!=NULL) {
            node* t=trees[n->degree];
            if(t==n)break;
            trees[n->degree]=NULL;
            if((n->value).second < (t->value).second) {
                t->prev->next=t->next;
                t->next->prev=t->prev;
                _addChild(n,t);
            } else {
                t->prev->next=t->next;
                t->next->prev=t->prev;
                if(n->next==n) {
                    t->next=t->prev=t;
                    _addChild(t,n);
                    n=t;
                } else {
                    n->prev->next=t;
                    n->next->prev=t;
                    t->next=n->next;
                    t->prev=n->prev;
                    _addChild(t,n);
                    n=t;
                }
            }
            continue;
        } else {
            trees[n->degree]=n;
        }
        n=n->next;
    }
    node* min = n;
    do {
        // cout << (n->value).second << " " << (min->value).second << endl;
        if((n->value).second < (min->value).second)
            min=n;
        n=n->next;
    } while(n != min);
    return min;
}

node* FibonacciHeap::_cut(node* heap, node* n) {
    if(n->next==n) {
        n->parent->child=NULL;
    } else {
        n->next->prev=n->prev;
        n->prev->next=n->next;
        n->parent->child=n->next;
    }
    n->next=n->prev=n;
    n->marked=false;
    return _merge(heap,n);
}

node* FibonacciHeap::_decreaseKey(node* heap, node* n, int value) {
    if((n->value).second < value)return heap;
    (n->value).second = value;
    if((n->value).second < (n->parent->value).second) {
        heap = _cut(heap,n);
        node* parent = n->parent;
        n->parent = NULL;
        while(parent != NULL && parent->marked) {
            heap = _cut(heap, parent);
            n = parent;
            parent = n->parent;
            n->parent = NULL;
        }
        if(parent != NULL && parent->parent != NULL) parent->marked=true;
    }
    return heap;
}

node* FibonacciHeap::_find(node* heap, pair<int, int> value) {
    node* n = heap;
    if(n == NULL)return NULL;
    do {
        if(n->value == value)return n;
        node* ret = _find(n->child,value);
        if(ret)return ret;
        n = n->next;
    }while(n != heap);
    return NULL;
}
