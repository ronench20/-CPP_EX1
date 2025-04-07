//ronen.chereshn@msmail.ariel.ac.il

#include <iostream>
#include "Graph.hpp"
#include "Algorithms.hpp"

int main() {
    Algorithms alg;
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2, 2);
    graph.addEdge(1, 3, 2);
    graph.addEdge(2, 4);
    graph.addEdge(4, 1, 6);
    std::cout << "printing basic graph\n";
    graph.printGraph();
    std::cout << "\n";

    Graph gBFS = alg.bfs(graph, 0);
    std::cout << "printing BFS graph\n";
    gBFS.printGraph();

    Graph gDFS = alg.dfs(graph, 0);
    std::cout << "printing DFS graph\n";
    gDFS.printGraph();

    Graph gDijkstra = alg.dijkstra(graph, 0);
    std::cout << "printing Dijkstra graph\n";
    gDijkstra.printGraph();
    std::cout << "\n";

    std::cout << "removing edge 0-1 and printing bfs and dfs again on the new graph\n";
    graph.removeEdge(0, 1);
    graph.printGraph();
    alg.bfs(graph, 0);
    alg.dfs(graph, 0);
    std::cout << "\n";

    std::cout << "graph for minimum spanning tree\n";
    Graph sGraph(9);
    sGraph.addEdge(0, 1, 9);
    sGraph.addEdge(0, 3);
    sGraph.addEdge(1, 2, 3);
    sGraph.addEdge(1, 4, 4);
    sGraph.addEdge(1, 5, 3);
    sGraph.addEdge(2, 3, 5);
    sGraph.addEdge(2, 4);
    sGraph.addEdge(2, 5, 12);
    sGraph.addEdge(3, 6, 8);
    sGraph.addEdge(4, 8, 6);
    sGraph.addEdge(5, 6, 5);
    sGraph.addEdge(5, 7, 2);
    sGraph.addEdge(6, 7, 2);
    sGraph.addEdge(7, 8);
    sGraph.printGraph();

    Graph gPrim = alg.prim(sGraph);
    std::cout << "\n";
    std::cout << "printing Prim's algorithm\n";
    gPrim.printGraph();
    std::cout << "\n";

    std::cout << "printing Kruskal's algorithm\n";
    Graph gKruskal = alg.kruskal(sGraph);
    gKruskal.printGraph();

    return 0;
}