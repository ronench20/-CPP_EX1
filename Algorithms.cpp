#include "Algorithms.hpp"
#include "Graph.hpp"
#include <iostream>
#define MAX_VALUE 2^32

using namespace std;

void Algorithms::enqueue(int *queue, int &rear, int value) {
    queue[rear++] = value;
}
int Algorithms::dequeue(int *queue, int &front) {
    return queue[front++];
}
bool Algorithms::isEmpty(int front, int rear) {
    return (front == rear);
}

Graph Algorithms::bfs(Graph &graph,int src){
    bool visited[MAX_VALUE] = {false};
    int queue[MAX_VALUE];
    int front = 0;
    int rear = 0;

    visited[src] = true;
    enqueue(queue, rear, src);
    while (!isEmpty(front,rear)){
        int curr = dequeue(queue, front);
        cout << curr << " ";

        Node* temp = graph.adjList[curr];
        while (temp != nullptr){
            int next = temp ->vertex;
            if (!visited[next]){
                visited[next] = true;
                enqueue(queue, rear, next);
            }
            temp = temp->next;
        }
    }
    cout << endl;
    return graph;
}
