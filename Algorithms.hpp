#ifndef CPP_EX1_ALGORITHMS_HPP
#define CPP_EX1_ALGORITHMS_HPP
#include "Graph.hpp"



class Algorithms {
private:
    int** queue(int src, int dest, int weight);

public:
    Graph bfs(Graph &graph,int src);
    Graph dfs(Graph &graph, int src);
    Graph dijkstra(Graph &graph, int src);
    Graph prim(Graph &graph, int src);
    Graph kruskal(Graph &graph, int src);
};


#endif //CPP_EX1_ALGORITHMS_HPP
