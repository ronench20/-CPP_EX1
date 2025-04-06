//ronen.chereshn@msmail.ariel.ac.il

#include "Graph.hpp"
#include <iostream>

using namespace graph;

/**
 * Constructs a Graph object with a specified number of vertices.
 *
 * @param vertices The number of vertices in the graph.
 */
Graph::Graph(int vertices) {
    numOfVertices = vertices;
    adjList = new Node* [vertices];
    for (int i = 0; i < vertices; ++i) {
        adjList[i] = nullptr;
    }
}

/**
 *Destructor for the Graph class.
 *
 * Deallocates memory used for the adjacency list.
 */
Graph::~Graph(){
    for (int i = 0; i < numOfVertices; ++i) {
        Node* curr = adjList[i];
        while (curr != nullptr) {
            Node *temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
    delete[] adjList;
}

/**
 * Adds an edge to the graph.
 *
 * @param src The source vertex.
 * @param dest The destination vertex.
 * @param weight The weight of the edge.
 * @throws std::invalid_argument if the source or destination vertex is invalid.
 */
void Graph::addEdge(int src, int dest, int weight) {
    if(src < 0 || src >= numOfVertices || dest < 0 || dest >= numOfVertices){
        std::cout << "invalid Node\n";
        throw std::invalid_argument("invalid Node");
    }
    Node* newNode = new Node;
    newNode ->vertex = dest;
    newNode ->weight = weight;
    newNode ->next = adjList[src];
    adjList[src] = newNode;

    Node* newNodeS = new Node;
    newNodeS ->vertex = src;
    newNodeS ->weight = weight;
    newNodeS ->next = adjList[dest];
    adjList[dest] = newNodeS;
}

/**
 * Removes an edge from the graph.
 *
 * @param src The source vertex.
 * @param dest The destination vertex.
 * @throws std::invalid_argument if the source or destination vertex is invalid.
 */
void Graph::removeEdge(int src, int dest) {
    if (src < 0 || src >= numOfVertices || dest < 0 || dest >= numOfVertices){
        std::cout << "invalid Node\n";
        throw std::invalid_argument("invalid Node");
    }
    Node* curr = adjList[src];
    Node* prev = nullptr;
    while (curr != nullptr && curr -> vertex != dest){
        prev = curr;
        curr = curr -> next;
    }
    if (curr != nullptr){
        if (prev == nullptr){
            adjList[src] = curr -> next;
        } else{
            prev ->next = curr->next;
        }
        delete curr;
    }

    curr = adjList[dest];
    prev = nullptr;
    while (curr != nullptr && curr -> vertex != src) {
        prev = curr;
        curr = curr->next;
    }
    if (curr != nullptr){
        if (prev == nullptr){
            adjList[dest] = curr -> next;
        } else{
            prev ->next = curr ->next;
        }
        delete curr;
    }
}

/**
 * Displays each vertex and its adjacent vertices with edge weights.
 */
void Graph::printGraph() {
    for (int i = 0; i < numOfVertices; ++i) {
        std::cout << "Node " << i << ":";
        Node* curr = adjList[i];
        while (curr != nullptr){
            std::cout << " (" << curr ->vertex << ", weight=" << curr ->weight << ")";
            curr = curr ->next;
        }
        std::cout << std::endl;
    }
}

/**
 * @return The number of vertices.
 */
int Graph::getNumOfVertices() const {
    return numOfVertices;
}