//ronen.chereshn@msmail.ariel.ac.il

#include "Algorithms.hpp"
#include "Graph.hpp"
#include <iostream>
#include "Queue.hpp"
#include "Stack.hpp"
#include "UnionFind.hpp"
#define MAX_VALUE 1024
#define INFINITY 99999999

using namespace std;

/**
 * Performs Breadth-First Search (BFS) on the given graph starting from the source vertex.
 * @param graph The input graph.
 * @param src The source vertex to start BFS.
 * @return A new graph representing the BFS traversal.
 */
Graph Algorithms::bfs(const Graph &graph, int src) {
    Graph newGraph(graph.getNumOfVertices());
    bool visited[MAX_VALUE] = {false};
    Queue queue;

    visited[src] = true;
    queue.enqueue(src);
    while (!queue.isEmpty()) {
        int curr = queue.dequeue();
        if (curr == -1) {
            break;
        }

        Node* temp = graph.adjList[curr];
        while (temp != nullptr) {
            int next = temp->vertex;
            if (!visited[next]) {
                visited[next] = true;
                newGraph.addEdge(curr, next, 0);
                queue.enqueue(next);
            }
            temp = temp->next;
        }
    }
    return newGraph;
}

/**
 * Performs Depth-First Search (DFS) on the given graph starting from the source vertex.
 * @param graph The input graph.
 * @param src The source vertex to start DFS.
 * @return A new graph representing the DFS traversal.
 */
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
    return newGraph;
}

/**
 * Relaxes the edge between two vertices.
 * @param u The source vertex.
 * @param v The destination vertex.
 * @param weight The weight of the edge.
 * @param dist The array of distances from the source vertex.
 * @param prev The array of previous vertices in the shortest path.
 */
void Algorithms::relax(int u, int v, int weight, int *dist, int *prev) {
    if (dist[u] + weight < dist[v]) {
        dist[v] = dist[u] + weight;
        prev[v] = u;
    }
}

/**
 * Finds the vertex with the minimum distance that has not been visited.
 * @param dist The array of distances from the source vertex.
 * @param visited The array of visited vertices.
 * @param numOfVertices The number of vertices in the graph.
 * @return The vertex with the minimum distance.
 */
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

/**
 * Performs Dijkstra's algorithm on the given graph starting from the source vertex.
 * @param graph The input graph.
 * @param src The source vertex to start Dijkstra's algorithm.
 * @return A new graph representing the shortest paths from the source vertex.
 */
Graph Algorithms::dijkstra(const Graph &graph, int src) {
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

/**
 * Performs Prim's algorithm to find the Minimum Spanning Tree (MST) of the given graph.
 * @param graph The input graph.
 * @return A new graph representing the MST.
 */
Graph Algorithms::prim(const Graph& graph) {
    int numOV = graph.getNumOfVertices();
    Graph newGraph(numOV);
    int key[MAX_VALUE];
    int pi[MAX_VALUE];
    bool notTreated[MAX_VALUE];

    for (int v = 0; v < numOV; v++) {
        key[v] = INFINITY;
        pi[v] = -1;
        notTreated[v] = true;
    }
    int s = 0;
    key[s] = 0;
    pi[s] = -1;

    while (true) {
        int minKey = INFINITY;
        int u = -1;
        for (int i = 0; i < numOV; i++) {
            if (notTreated[i] && key[i] < minKey) {
                minKey = key[i];
                u = i;
            }
        }
        if (u == -1) {
            break;
        }
        notTreated[u] = false;
        Node* temp = graph.adjList[u];
        while (temp != nullptr) {
            int v = temp->vertex;
            int weight = temp->weight;
            if (notTreated[v] && weight < key[v]) {
                pi[v] = u;          // π[v] ← u
                key[v] = weight;    // key[v] ← w(u,v)
            }
            temp = temp->next;
        }
    }
    for (int v = 0; v < numOV; v++) {
        if (pi[v] != -1) {
            newGraph.addEdge(pi[v], v, key[v]);
        }
    }
    return newGraph;
}

/**
 * Performs Kruskal's algorithm to find the Minimum Spanning Tree (MST) of the given graph.
 * @param graph The input graph.
 * @return A new graph representing the MST.
 */
Graph Algorithms::kruskal(const Graph &graph) {
    int numOV = graph.getNumOfVertices();
    Graph newGraph(numOV);
    Node edges[MAX_VALUE];
    int src[MAX_VALUE];
    int edgeCount = 0;

    for (int u = 0; u < numOV; ++u) {
        Node* temp = graph.adjList[u];
        while (temp != nullptr) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (u < v) {
                edges[edgeCount].vertex = v;
                edges[edgeCount].weight = weight;
                src[edgeCount] = u;
                edgeCount++;
            }
            temp = temp->next;
        }
    }
    for (int i = 0; i < edgeCount - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < edgeCount; ++j) {
            if (edges[j].weight < edges[minIndex].weight) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            Node temporary = edges[i];
            edges[i] = edges[minIndex];
            edges[minIndex] = temporary;

            int newSrc = src[i];
            src[i] = src[minIndex];
            src[minIndex] = newSrc;
        }
    }
    UnionFind unionFind;
    unionFind.makeSet(numOV);
    for (int i = 0; i < edgeCount; ++i) {
        int u = src[i];
        int v = edges[i].vertex;
        int weight = edges[i].weight;
        if (!unionFind.isConnected(u, v)) {
            unionFind.unite(u, v);
            newGraph.addEdge(u, v, weight);
        }
    }
    return newGraph;
}