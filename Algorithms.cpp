#include "Algorithms.hpp"
#include "Graph.hpp"
#include <iostream>
#define MAX_VALUE 2^32

using namespace std;

//int** Algorithms::queue(int src, int dest, int weight){
//    Node* newNode = new Node;
//    newNode ->vertex = dest;
//    newNode ->weight = weight;
//    newNode ->next = adjList[src];
//    adjList[src] = newNode;
//}

Graph Algorithms::bfs(Graph &graph,int src){
    bool visited[MAX_VALUE] = {false};
    int queue[MAX_VALUE];
    int front = 0;
    int rear = 0;

    visited[src] = true;
    queue[rear++] =src;
    while (front < rear){
        int curr = queue[front++];
        cout << curr << " ";
        Node* temp = graph.adjList[curr];
        while (temp != nullptr){
            int next = temp->vertex;
            if (!visited[next]){
                visited[next] = true;
                queue[rear++] = next;
            }
            temp = temp ->next;
        }
    }
    cout << endl;
    return graph;
}
