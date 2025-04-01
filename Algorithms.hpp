#ifndef CPP_EX1_ALGORITHMS_HPP
#define CPP_EX1_ALGORITHMS_HPP
#include "Graph.hpp"



class Algorithms {
private:
    void enqueue(int queue[], int &rear, int value);
    int dequeue(int queue[], int &front);
    bool isEmpty(int front, int rear);

public:
    Graph bfs(Graph &graph,int src);
    Graph dfs(Graph &graph, int src);
    Graph dijkstra(Graph &graph, int src);
    Graph prim(Graph &graph, int src);
    Graph kruskal(Graph &graph, int src);
};


#endif //CPP_EX1_ALGORITHMS_HPP
