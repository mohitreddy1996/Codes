//
// Created by mohit on 22/10/17.
//

#include <bits/stdc++.h>
#include "binomial_heap.h"
#include "binary_heap.h"
#include "fibonacci_heap.h"

#define MAX 100004

using namespace std;

vector<pair<int, int> > v[MAX];
int dist[MAX], parent[MAX];
int num_nodes, source;

void initializeWeight() {
    for (int i = 0; i <= num_nodes; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
}

void printStats() {
    cout << "\n Distance and shortest path from source. \n";
    for (int i = 1; i <= num_nodes; i++) {
        cout << "Node: " << i << " Distance: ";
        if (dist[i] == INT_MAX) {
            cout << "Not reachable\n";
        } else {
            cout << dist[i] << " Path: " << i;
            int temp = i;
            if (i == source) {
                cout << endl;
                continue;
            }
             do {
                cout << "-" << parent[temp];
                temp = parent[temp];
            } while (parent[temp] != -1);
            cout << endl;
        }
    }
}

void performDijkstraBinomialHeaps() {
    cout << "\n** Binomial Heaps **\n";
    BinomialHeap *binomialHeap = new BinomialHeap();
    dist[source] = 0;
    parent[source] = -1;
    binomialHeap->insert(make_pair(source, dist[source]));
    while (!binomialHeap->isEmpty()) {
        pair<int, int> p = (binomialHeap->getMin())->data;
        // cout << p.first << " " << p.second << endl;
        binomialHeap->extractMin();
        for (int i = 0; i < v[p.first].size(); i++) {
            if (dist[v[p.first][i].first] > v[p.first][i].second + p.second) {
                parent[v[p.first][i].first] = p.first;
                dist[v[p.first][i].first] = v[p.first][i].second + p.second;
                binomialHeap->insert(make_pair(v[p.first][i].first, dist[v[p.first][i].first]));
            }
        }
    }
    printStats();
    return;
}

void performDijkstraBinaryHeaps() {
    cout << "\n** Binary Heaps **\n";
    MinHeap *minHeap = new MinHeap(MAX);
    dist[source] = 0;
    parent[source] = -1;
    minHeap->insertKey(make_pair(source, dist[source]));
    while (!minHeap->isEmpty()) {
        pair<int, int> p = minHeap->getMin();
        minHeap->extractMin();
        for (int i = 0; i < v[p.first].size(); i++) {
            if (dist[v[p.first][i].first] > v[p.first][i].second + p.second) {
                parent[v[p.first][i].first] = p.first;
                dist[v[p.first][i].first] = v[p.first][i].second + p.second;
                minHeap->insertKey(make_pair(v[p.first][i].first, dist[v[p.first][i].first]));
            }
        }
    }
    printStats();
    return;
}

void performDijkstraFibonacciHeaps() {
    cout << "\n** Fibonacci Heaps **\n";
    FibonacciHeap *fibonacciHeap = new FibonacciHeap();
    dist[source] = 0;
    parent[source] = -1;
    fibonacciHeap->insert(make_pair(source, dist[source]));
    while (!(fibonacciHeap->isEmpty())) {
        pair<int, int> p = fibonacciHeap->getMinimum();
        fibonacciHeap->removeMinimum();
        for (int i = 0; i < v[p.first].size(); i++) {
            if (dist[v[p.first][i].first] > v[p.first][i].second + p.second) {
                parent[v[p.first][i].first] = p.first;
                dist[v[p.first][i].first] = v[p.first][i].second + p.second;
                fibonacciHeap->insert(make_pair(v[p.first][i].first, dist[v[p.first][i].first]));
            }
        }
    }
    printStats();
    return;
}


int main () {
    freopen("input.txt", "r", stdin);
    cin >> num_nodes;
    cout << num_nodes;
    cin >> source;
    cout << source;
    int src, dest, weight;
    while (cin >> src >> dest >> weight) {
        if (src == -1 || dest == -1) {
            break;
        }
        if (weight < 0) {
            printf("Dijsktra not good for negative weights.\n");
            exit(0);
        }
        v[src].push_back(make_pair(dest, weight));
        v[dest].push_back(make_pair(src, weight));
    }

    // Binomial Heaps.
    // Initialise dist.
    initializeWeight();
    clock_t begin1 = clock();
    performDijkstraBinomialHeaps();
    cout << " Binomial Heaps Time: " << float(clock() - begin1) / (CLOCKS_PER_SEC) << endl;

    // Binary Heaps.
    // Initialise dist.
    initializeWeight();
    begin1 = clock();
    performDijkstraBinaryHeaps();
    cout << " Binary Heaps Time: " << float(clock() - begin1) / (CLOCKS_PER_SEC) << endl;

    // Fibonacci Heaps.
    // Initialise dist.
    initializeWeight();
    begin1 = clock();
    performDijkstraFibonacciHeaps();
    cout << " Fibonacci Heaps Time: " << float(clock() - begin1) / (CLOCKS_PER_SEC) << endl;
    return 0;
}