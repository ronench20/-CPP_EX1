//ronen.chereshn@msmail.ariel.ac.il

#ifndef CPP_EX1_ALGORITHMS_HPP
#define CPP_EX1_ALGORITHMS_HPP
#include "Graph.hpp"

using namespace graph;

class Algorithms {
private:
    /**
     * Relaxes the edge between two vertices.
     *
     * @param u The source vertex.
     * @param v The destination vertex.
     * @param weight The weight of the edge.
     * @param dist The array of distances from the source.
     * @param prev The array of previous vertices in the path.
     */
    void relax(int u, int v, int weight, int *dist, int *prev);

    /**
     * Finds the vertex with the minimum distance that has not been visited.
     *
     * @param dist The array of distances from the source.
     * @param visited The array of visited vertices.
     * @param numOfVertices The number of vertices in the graph.
     * @return The index of the vertex with the minimum distance.
     */
    int findMinVertex(int *dist, bool *visited, int numOfVertices);

public:
    /**
     * Performs Breadth-First Search (BFS) on the graph starting from the source vertex.
     *
     * @param graph The graph to perform BFS on.
     * @param src The source vertex.
     * @return A graph representing the BFS traversal.
     */
    Graph bfs(const Graph &graph, int src);

    /**
     * Performs Depth-First Search (DFS) on the graph starting from the source vertex.
     *
     * @param graph The graph to perform DFS on.
     * @param src The source vertex.
     * @return A graph representing the DFS traversal.
     */
    Graph dfs(const Graph &graph, int src);

    /**
     * Performs Dijkstra's algorithm on the graph starting from the source vertex.
     *
     * @param graph The graph to perform Dijkstra's algorithm on.
     * @param src The source vertex.
     * @return A graph representing the shortest paths from the source vertex.
     */
    Graph dijkstra(const Graph &graph, int src);

    /**
     * Performs Prim's algorithm to find the Minimum Spanning Tree (MST) of the graph.
     *
     * @param graph The graph to perform Prim's algorithm on.
     * @return A graph representing the MST.
     */
    Graph prim(const Graph &graph);

    /**
     * Performs Kruskal's algorithm to find the Minimum Spanning Tree (MST) of the graph.
     *
     * @param graph The graph to perform Kruskal's algorithm on.
     * @return A graph representing the MST.
     */
    Graph kruskal(const Graph &graph);
};

#endif //CPP_EX1_ALGORITHMS_HPP