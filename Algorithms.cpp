//ronen.chereshn@msmail.ariel.ac.il

#include "Algorithms.hpp"
#include "Graph.hpp"
#include <iostream>
#include "Queue.hpp"
#include "Stack.hpp"
#define MAX_VALUE 1024
#define INFINITY 99999999

using namespace std;


Graph Algorithms::bfs(const Graph &graph,int src){
    Graph newGraph(graph.getNumOfVertices());
    bool visited[MAX_VALUE] = {false};
    Queue queue;

    visited[src] = true;
    queue.enqueue(src);
    while (!queue.isEmpty()){
        int curr = queue.dequeue();
        if(curr == -1){
            break;
        }
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
        if (curr == -1) {
            break;
        }

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

void Algorithms::relax(int u, int v, int weight, int *dist, int *prev) {
    if (dist[u] + weight < dist[v]) {
        dist[v] = dist[u] + weight;
        prev[v] = u;
    }
}

int Algorithms::findMinVertex(int *dist, bool *visited, int numOfVertices) {
    int minValue = INFINITY;
    int minVertex = -1;
    for (int i = 0; i < numOfVertices; i++) {
        if (!visited[i] && dist[i] < minValue) {
            minValue = dist[i];
            minVertex = i;
        }
    }
    return minVertex;
}
Graph Algorithms::dijkstra(Graph &graph, int src) {
    int numOV = graph.getNumOfVertices();
    Graph newGraph(numOV);
    int dist[MAX_VALUE];
    int prev[MAX_VALUE];
    bool visited[MAX_VALUE] = {false};
    for (int i = 0; i < numOV; i++) {
        dist[i] = MAX_VALUE;
        prev[i] = -1;
    }
    dist[src] = 0;
    for (int i = 0; i < numOV; ++i) {
        int u = findMinVertex(dist, visited, numOV);
        if (u == -1) {
            break;
        }
        visited[u] = true;
        Node* temp = graph.adjList[u];
        while (temp != nullptr) {
            int v = temp->vertex;
            int weight = temp->weight;
            relax(u, v, weight, dist, prev);
            temp = temp->next;
        }
    }
    for (int v = 0; v < numOV; ++v) {
        if (prev[v] != -1) {
            Node* temp = graph.adjList[prev[v]];
            while (temp != nullptr) {
                if (temp->vertex == v) {
                    newGraph.addEdge(prev[v], v, temp->weight);
                    break;
                }
                temp = temp->next;
            }
        }
    }
    return newGraph;
}

Graph Algorithms::prim(const Graph &graph) {
    int numOV = graph.getNumOfVertices();
    Graph newGraph(numOV);
    int key[MAX_VALUE];
    int pi[MAX_VALUE];
    bool notTreated[MAX_VALUE] = {false};
    for (int u = 0; u < numOV; u++) {
        key[u] = INFINITY;
        pi[u] = -1;
        notTreated[u] = true;
    }
    int s = 0;
    key[s] = 0;
    pi[s] = -1;

    while (true){
        int u = findMinVertex(key, notTreated, numOV);
        cout << "chosen u: " << u << "\n";
        if (u == -1) {
            break;
        }
        notTreated[u] = false;
        Node* temp = graph.adjList[u];
        while (temp != nullptr) {
            int v = temp->vertex;
            int weight = temp->weight;
            if (notTreated[v] && weight < key[v]) {
                pi[v] = u;
                key[v] = weight;
            }
            temp = temp->next;
        }
    }
    for (int v = 0; v < numOV; ++v) {
        if (pi[v] != -1) {
            newGraph.addEdge(pi[v], v, key[v]);
        }
    }
    return newGraph;
}
