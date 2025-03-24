
#ifndef CPP_EX1_GRAPH_H
#define CPP_EX1_GRAPH_H

struct Node{
    int vertex;
    int weight;
    Node* next;
};

class Graph{
private:
    int numOfVertices;
    Node** adjList;

public:
    Graph(int vertices);
    ~Graph();

    void addEdge(int src, int dest, int weight = 1);
    void removeEdge(int src, int dest);
    void printGraph();
};


#endif //CPP_EX1_GRAPH_H
