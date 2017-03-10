//
// Created by mohit on 10/3/17.
//


/**
 * Input
1 2 3
1 5 3
1 3 4
2 3 7
2 4 3
3 5 6
4 3 4
4 5 6
5 2 5
0
 * */
#include <bits/stdc++.h>
#define MAX_NODES 100000
#define MAX_VALUE 100000
using namespace std;

// graph specifics
vector<pair<int, int> > graph[MAX_NODES];

// dijsktra specifics
int dist[MAX_NODES];

void initialise(){
    for(int i=0; i<MAX_NODES; i++){
        dist[i] = MAX_VALUE;
    }
}

void dijsktra(int source){
    initialise();
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

void print_ans(int nodes, int source){
    for(int i=1; i<=nodes; i++){
        cout<<"Distance Between Source : "<<source<<" And Node : "<<i<<" : "<<dist[i]<<endl;
    }
}

int main(){

    int nodes;
    cout<<"Enter the Number of Nodes in the Graph : ";
    cin>>nodes;

    cout<<"Enter the Edges : (Starting Vertex -> Ending Vertex) and Weights";
    cout<<"\nEnter 0 to end the Edges\n";

    while(1){
        int x, y, w;
        cin>>x;
        if(x==0)
            break;
        cin>>y>>w;
        graph[x].push_back(make_pair(y, w));
    }

    int source;
    cout<<"\nEnter the Source : ";
    cin>>source;

    dijsktra(source);

    print_ans(nodes, source);

    return 0;
}