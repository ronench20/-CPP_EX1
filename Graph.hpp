//ronen.chereshn@msmail.ariel.ac.il

#ifndef CPP_EX1_GRAPH_HPP
#define CPP_EX1_GRAPH_HPP

struct Node {
    int vertex;
    int weight;
    Node *next;
};

class Graph {
private:
    int numOfVertices;

public:
    Node **adjList;
    Graph(int vertices);
    //~Graph();
    void addEdge(int src, int dest, int weight = 1);
    void removeEdge(int src, int dest);
    void printGraph();

    int getNumOfVertices() const;
};

#endif //CPP_EX1_GRAPH_HPP
