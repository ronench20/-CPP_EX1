#include <iostream>
#include "Graph.hpp"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    Graph graph(5);
    graph.addEdge(0,1);
    graph.addEdge(0,2,2);
    graph.addEdge(1,3,2);
    graph.addEdge(2,4);
    graph.printGraph();

    graph.removeEdge(0,1);
    graph.printGraph();

    return 0;
}