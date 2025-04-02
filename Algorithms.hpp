#ifndef CPP_EX1_ALGORITHMS_HPP
#define CPP_EX1_ALGORITHMS_HPP
#include "Graph.hpp"



class Algorithms {

public:
    Graph bfs(const Graph &graph,int src);
    Graph dfs(const Graph &graph, int src);
    Graph dijkstra(Graph &graph, int src);
    Graph prim(Graph &graph, int src);
    Graph kruskal(Graph &graph, int src);
};


#endif //CPP_EX1_ALGORITHMS_HPP
