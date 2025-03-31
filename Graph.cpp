#include "Graph.hpp"
#include <iostream>

Graph::Graph(int vertices) {
    numOfVertices = vertices;
    adjList = new Node * [vertices];
    for (int i = 0; i < vertices; ++i) {
        adjList[i] = nullptr;
    }
}

//destructor
Graph::~Graph(){
    for (int i = 0; i < numOfVertices; ++i) {
        Node* curr = adjList[i];
        while (curr != nullptr) { //check why does it's not working without
            Node *temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
    delete[] adjList;
}

void Graph::addEdge(int src, int dest, int weight) {
    if(src < 0 || src >= numOfVertices || dest < 0 || dest >= numOfVertices){
        std::cout << "invalid Node\n";
        return;
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

void Graph::removeEdge(int src, int dest) {
    if (src < 0 || src >= numOfVertices || dest < 0 || dest >= numOfVertices){
        std::cout << "invalid Node\n";
        return;
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

void Graph::printGraph() {
    for (int i = 0; i < numOfVertices; ++i) {
        std::cout << "Node " << i << ":";
        Node* curr = adjList[i];
        while (curr != nullptr){
            std::cout << " (" << curr ->vertex << ", weight= " << curr ->weight << ")";
            curr = curr ->next;
        }
        std::cout << std::endl;
    }
}