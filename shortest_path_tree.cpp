//
// Created by mohit on 9/3/17.
//

#include <bits/stdc++.h>
#define MAX_NODES 100000
#define MAX_VALUE 100000
using namespace std;

// Graph specifics
vector<pair<int, int> > graph[MAX_NODES];
int origin;
int dist[MAX_NODES];

// shortest path tree specifics.
vector<pair<int, int> > shortest_path_tree;


void initialise_weights(){
    for(int i=0; i<MAX_NODES; i++){
        dist[i] = MAX_VALUE;
    }
}
void draw_shortest_path_tree(){

    initialise_weights();
    priority_queue<pair<int, int>> distance_node_priority_queue;

    dist[origin] = 0;
    distance_node_priority_queue.push(make_pair(dist[origin], origin));
    while(!distance_node_priority_queue.empty()){
        int vertex = distance_node_priority_queue.top().second;
        distance_node_priority_queue.pop();
        for(int i=0; i<graph[vertex].size(); i++){
            int newVertex = graph[vertex][i].first;
            int edgeWeight = graph[vertex][i].second;

            if(dist[newVertex] > dist[vertex] + edgeWeight){
                dist[newVertex] = dist[vertex] + edgeWeight;
                distance_node_priority_queue.push(make_pair(dist[newVertex], newVertex));

                shortest_path_tree.push_back(make_pair(vertex, newVertex));
            }
        }
    }

}

void print_shortest_path_tree(){
    cout<<"Shortest Path Tree\n";
    for(int i=0; i<shortest_path_tree.size(); i++){
        cout<<shortest_path_tree[i].first<<" ----> "<<shortest_path_tree[i].second<<"\n";
    }
}

int main(){
    int nodes;
    cout<<"Enter the Number of Nodes in the Graph : ";
    cin>>nodes;

    // Vertex numbering from 1.
    cout<<"Enter the Edges : (Starting vertex -> Ending Vertex) and Weights ";
    cout<<"\nEnter 0 to end the edges\n";
    while(1){
        int x, y, w;
        cin>>x;
        if(x==0)
            break;
        cin>>y>>w;
        graph[x].push_back(make_pair(y, w));
    }

    cout<<"\nChoose the root/Origin : ";
    cin>>origin;

    draw_shortest_path_tree();

    print_shortest_path_tree();
    return 0;
}