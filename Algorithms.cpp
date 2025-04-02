#include "Algorithms.hpp"
#include "Graph.hpp"
#include <iostream>
#include "Queue.hpp"
#include "Stack.hpp"
#define MAX_VALUE 1024

using namespace std;


//void Algorithms::enqueue(int *queue, int &rear, int value) {
//    queue[rear++] = value;
//}
//int Algorithms::dequeue(int *queue, int &front) {
//    return queue[front++];
//}
//bool Algorithms::isEmpty(int front, int rear) {
//    return (front == rear);
//}

Graph Algorithms::bfs(const Graph &graph,int src){
    Graph newGraph(graph.getNumOfVertices());
    bool visited[MAX_VALUE] = {false};
    Queue queue;

    visited[src] = true;
    queue.enqueue(src);
    while (!queue.isEmpty()){
        int curr = queue.dequeue();
        cout << curr << " ";

        Node* temp = graph.adjList[curr];
        while (temp != nullptr){
            int next = temp ->vertex;
            if (!visited[next]){
                visited[next] = true;
                newGraph.addEdge(curr, next, 0);
                queue.enqueue(next);
            }
            temp = temp->next;
        }
    }
    cout << endl;
    return newGraph;
}

Graph Algorithms::dfs(const Graph &graph, int src) {
    Graph newGraph(graph.getNumOfVertices());
    bool visited[MAX_VALUE] = {false};
    Stack stack;

    stack.push(src);

    while (!stack.isEmpty()) {
        int curr = stack.pop();

        if (visited[curr]) continue;
        visited[curr] = true;

        cout << curr << " ";

        Node* temp = graph.adjList[curr];
        int children[MAX_VALUE];
        int childrenCount = 0;

        while (temp != nullptr) {
            int neighbor = temp->vertex;
            if (!visited[neighbor]) {
                newGraph.addEdge(curr, neighbor, 0);
                children[childrenCount++] = neighbor;
            }
            temp = temp->next;
        }

        for (int i = childrenCount - 1; i >= 0; i--) {
            stack.push(children[i]);
        }
    }

    cout << endl;
    return newGraph;
}


Graph Algorithms::dijkstra(Graph &graph, int src) {

}
