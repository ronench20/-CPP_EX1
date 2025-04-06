//ronen.chereshn@msmail.ariel.ac.il

#ifndef CPP_EX1_ALGORITHMS_HPP
#define CPP_EX1_ALGORITHMS_HPP
#include "Graph.hpp"

using namespace graph;


class Algorithms {
private:
    void relax(int u, int v, int weight, int *dist, int *prev);
    int findMinVertex(int *dist, bool *visited, int numOfVertices);

public:
    Graph bfs(const Graph &graph,int src);
    Graph dfs(const Graph &graph, int src);
    Graph dijkstra(const Graph &graph, int src);
    Graph prim(const Graph &graph);
    Graph kruskal(const Graph &graph);
};


#endif //CPP_EX1_ALGORITHMS_HPP
