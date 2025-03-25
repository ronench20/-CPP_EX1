#include "Graph.h"

#include <iostream>

Graph::Graph(int vertices) {
    numOfVertices = vertices;
    adjList = new Node * [vertices];
}

//destructor
Graph::~Graph(){
    for (int i = 0; i < numOfVertices; ++i) {
        Node curr = adjList[i];
        if (curr == NULL){ //check why does it's not working without
            break;
        }
        Node* temp = curr;
        curr = curr.next;
        delete temp;
    }
    delete[] adjList;
}

void Graph::addEdge(int src, int dest, int weight) {
    if(src < 0 || src >= numOfVertices || dest < 0 || dest >= numOfVertices){
        std::cout << "invalid Node\n"
        return;
    }
    Node* newNode = new Node;
    newNode ->vertex = src;
    newNode ->weight = weight;
    newNode ->next = adjList[src];
    adjList[src] = newNode;

    Node* newNodeS = new Node;
    newNodeS ->vertex = src;
    newNodeS ->weight = weight;
    newNodeS ->next = adjList[src];
    adjList[src] = newNodeS;
}

void Graph::removeEdge(int src, int dest) {
    if (src < 0 || src >= numOfVertices || dest < 0 || dest >= numOfVertices){
        std::cout << "invalid Node\n"
        return;
    }
    Node* curr = adjList[src];
    Node* prev = NULL;
    while (curr != NULL && curr -> vertex != src){
        prev = curr;
        curr = curr -> next;
    }
    if (curr != NULL){
        if (prev == NULL){
            adjList[dest] = curr -> next
        } else{
            prev ->next = curr->next;
        }
        delete curr;
    }
}

void Graph::printGraph() {
    for (int i = 0; i < numOfVertices; ++i) {
        std::cout << "Node " << i << ":";
        Node* curr = adjList[i];
        while (curr != NULL){
            std::cout << " (" << curr ->vertex << ", weight= " << curr ->weight << ")";
            curr = curr ->next;
        }
        std::cout << std::endl;
    }
}