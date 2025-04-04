//ronen.chereshn@msmail.ariel.ac.il

#ifndef CPP_EX1_ALGORITHMS_HPP
#define CPP_EX1_ALGORITHMS_HPP
#include "Graph.hpp"



class Algorithms {
    void relax(int u, int v, int weight, int *dist, int *prev);
    int findMinVertex(int *dist, bool *visited, int numOfVertices);

public:
    Graph bfs(const Graph &graph,int src);
    Graph dfs(const Graph &graph, int src);
    Graph dijkstra(Graph &graph, int src);
    Graph prim(const Graph &graph);
    Graph kruskal(Graph &graph);
};


#endif //CPP_EX1_ALGORITHMS_HPP
