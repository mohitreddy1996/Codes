#include <bits/stdc++.h>

#define MAX_NODES 100000
#define MAX_VALUE 100000
using namespace std;

int numVertices;
int numEdges;

vector<pair<int, pair<int, int> > > input;
vector<pair<int, int> > graph[MAX_NODES];

void Dijkstra(int source){

    int dist[MAX_NODES];

    for(int i=0; i<MAX_NODES; i++){
        dist[i] = MAX_VALUE;
    }

    dist[source] = 0;
    priority_queue<pair<int, int> > dijkstra_pq;
    dijkstra_pq.push(make_pair(0, source));

    while(!dijkstra_pq.empty()){
        int vertex = dijkstra_pq.top().second;
        dijkstra_pq.pop();

        for(int i=0; i<graph[vertex].size(); i++){
            int newVertex = graph[vertex][i].first;
            if(dist[newVertex] > dist[vertex] + graph[vertex][i].second){
                dist[newVertex] = dist[vertex] + graph[vertex][i].second;
                dijkstra_pq.push(make_pair(dist[newVertex], newVertex));
            }
        }
    }
}

void bellmanFord(int source, int vertices){
    int dist[MAX_NODES];

    for(int i=0; i<MAX_NODES; i++){
        dist[i] = MAX_VALUE;
    }

    dist[source] = 0;

    for(int i=1; i<=vertices-1; i++){
        for(int j=0; j<input.size(); j++){
            int u = input[j].first;
            int v = input[j].second.first;
            int w = input[j].second.second;

            if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }



}

int main(){
    numVertices = 100;
    numEdges = 1000;
    map<pair<int, int>, int> m;
    int count = 0;

    while(count < numEdges){
        int x = rand()%numVertices + 1;
        int y = rand()%numVertices + 1;
        if(x == y || m[make_pair(x, y)]){
            continue;
        }
        int w = rand()*10;
        graph[x].push_back(make_pair(y, w));
        input.push_back(make_pair(x, make_pair(y, w)));
        count++;
    }

    clock_t t1;
    clock_t t2;
    t1 = clock();
    Dijkstra(1);
    t2 = clock();
    cout<<"Dijkstra's Algorithm Execution Time : "<<(t2-t1)<<endl;

    t1 = clock();
    bellmanFord(1, numVertices);
    t2 = clock();
    cout<<"Bellman Ford Algorithm Execution Time : "<<(t2-t1)<<endl;

    return 0;
}