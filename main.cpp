#include <iostream>
#include "Graph.hpp"
#include "Algorithms.hpp"


int main() {
    Graph graph(5);
    Graph GD(5);
    graph.addEdge(0,1);
    graph.addEdge(0,2,2);
    graph.addEdge(1,3,2);
    graph.addEdge(2,4);
    graph.addEdge(4,1,6);
    graph.printGraph();
    Algorithms alg;
    //GD = alg.bfs(graph, 0);
    alg.dfs(graph, 0);
    GD = alg.dijkstra(graph, 0);
    GD.printGraph();

//    graph.removeEdge(0,1);
//    graph.printGraph();
//    alg.bfs(graph, 0);
//    alg.dfs(graph, 0);
    return 0;
}