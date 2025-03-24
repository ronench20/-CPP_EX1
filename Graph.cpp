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