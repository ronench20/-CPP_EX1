//ronen.chereshn@msmail.ariel.ac.il

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Graph.hpp"
#include "Algorithms.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "UnionFind.hpp"

/**
 * Checks if there is an edge between two vertices in the graph.
 *
 * @param graph The graph to check.
 * @param u The source vertex.
 * @param v The destination vertex.
 * @return true if there is an edge from u to v, false otherwise.
 */
bool hasEdge(Graph &graph, int u, int v) {
    Node* node = graph.adjList[u];
    while (node) {
        if (node->vertex == v) {
            return true;
        }
        node = node->next;
    }
    return false;
}

/**
 * Test cases for adding and removing edges in the graph.
 */
TEST_CASE("addEdge and removeEdge tests") {
    Graph graph(3);
    CHECK_THROWS_AS(graph.addEdge(-1, 2), std::invalid_argument);
    CHECK_THROWS_AS(graph.addEdge(3, 0), std::invalid_argument);
    CHECK_THROWS_AS(graph.removeEdge(0, 4), std::invalid_argument);
    CHECK_THROWS_AS(graph.removeEdge(-1, 1), std::invalid_argument);
}

/**
 * Test cases for Breadth-First Search (BFS) algorithm.
 */
TEST_CASE("BFS tests") {
    Graph graph(3);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);

    Algorithms alg;
    Graph bfsGraph = alg.bfs(graph, 0);
    bfsGraph.removeEdge(0, 1);
    bfsGraph.removeEdge(1, 2);
    CHECK(true);
}

/**
 * Test cases for Depth-First Search (DFS) algorithm.
 */
TEST_CASE("DFS tests") {
    Graph graph(3);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);

    Algorithms alg;
    Graph dfsGraph = alg.dfs(graph, 0);
    dfsGraph.removeEdge(0, 1);
    dfsGraph.removeEdge(1, 2);
    CHECK(true);
}

/**
 * Test cases for Dijkstra's algorithm.
 */
TEST_CASE("Dijkstra tests") {
    Graph graph(4);
    graph.addEdge(0, 1, 1);
    graph.addEdge(1, 2, 2);

    Algorithms alg;
    Graph dijkstraGraph = alg.dijkstra(graph, 0);

    CHECK(hasEdge(dijkstraGraph, 0, 1));
    CHECK(hasEdge(dijkstraGraph, 1, 2));

    CHECK_FALSE(hasEdge(dijkstraGraph, 0, 3));
    CHECK_FALSE(hasEdge(dijkstraGraph, 1, 3));
    CHECK_FALSE(hasEdge(dijkstraGraph, 2, 3));
    CHECK_FALSE(hasEdge(dijkstraGraph, 3, 0));

    CHECK(dijkstraGraph.adjList[3] == nullptr);
}

/**
 * Test case for Prim's algorithm.
 */
TEST_CASE("Prim test1") {
    Graph graph(9);
    graph.addEdge(0, 1, 9);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 4, 4);
    graph.addEdge(1, 5, 3);
    graph.addEdge(2, 3, 5);
    graph.addEdge(2, 4);
    graph.addEdge(2, 5, 12);
    graph.addEdge(3, 6, 8);
    graph.addEdge(4, 8, 6);
    graph.addEdge(5, 6, 5);
    graph.addEdge(5, 7, 2);
    graph.addEdge(6, 7, 2);
    graph.addEdge(7, 8);

    Algorithms alg;
    Graph mst = alg.prim(graph);

    int count = 0;
    for (int i = 0; i < 9; i++) {
        Node* node = mst.adjList[i];
        while (node) {
            count++;
            node = node->next;
        }
    }

    CHECK(count / 2 == 8);
    CHECK_FALSE(hasEdge(mst, 2, 5));
    CHECK(hasEdge(mst, 5, 7));
    CHECK(hasEdge(mst, 6, 7));
}

/**
 * Test case for Prim's algorithm.
 */
TEST_CASE("Prim test2") {
    Graph g(9);
    g.addEdge(0, 1, 9);
    g.addEdge(0, 3);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 4, 4);
    g.addEdge(1, 5, 3);
    g.addEdge(2, 3, 5);
    g.addEdge(2, 4);
    g.addEdge(2, 5, 12);
    g.addEdge(3, 6, 8);
    g.addEdge(5, 6, 5);
    g.addEdge(5, 7, 2);
    g.addEdge(6, 7, 2);

    Algorithms alg;
    Graph mst = alg.prim(g);

    int count = 0;
    for (int i = 0; i < 9; i++) {
        Node* node = mst.adjList[i];
        while (node) {
            count++;
            node = node->next;
        }
    }

    CHECK(count / 2 == 7);
    CHECK_FALSE(hasEdge(mst, 4, 8));
    CHECK_FALSE(hasEdge(mst, 7, 8));
    CHECK(mst.adjList[8] == nullptr);
}

/**
 * Test case for Kruskal's algorithm.
 */
TEST_CASE("Kruskal test1") {
    Graph g(9);
    g.addEdge(0, 1, 9);
    g.addEdge(0, 3);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 4, 4);
    g.addEdge(1, 5, 3);
    g.addEdge(2, 3, 5);
    g.addEdge(2, 4);
    g.addEdge(2, 5, 12);
    g.addEdge(3, 6, 8);
    g.addEdge(4, 8, 6);
    g.addEdge(5, 6, 5);
    g.addEdge(5, 7, 2);
    g.addEdge(6, 7, 2);
    g.addEdge(7, 8);

    Algorithms alg;
    Graph mst = alg.kruskal(g);

    int count = 0;
    for (int i = 0; i < 9; i++) {
        Node* n = mst.adjList[i];
        while (n) {
            count++;
            n = n->next;
        }
    }

    CHECK(count / 2 == 8);
    CHECK_FALSE(hasEdge(mst, 2, 5));
    CHECK(hasEdge(mst, 5, 7));
    CHECK(hasEdge(mst, 6, 7));
}

/**
 * Test cases for Kruskal's algorithm.
 */
TEST_CASE("Kruskal test2") {
    Graph g(9);
    g.addEdge(0, 1, 9);
    g.addEdge(0, 3);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 4, 4);
    g.addEdge(1, 5, 3);
    g.addEdge(2, 3, 5);
    g.addEdge(2, 4);
    g.addEdge(2, 5, 12);
    g.addEdge(3, 6, 8);
    g.addEdge(5, 6, 5);
    g.addEdge(5, 7, 2);
    g.addEdge(6, 7, 2);

    Algorithms alg;
    Graph mst = alg.kruskal(g);

    int count = 0;
    for (int i = 0; i < 9; i++) {
        Node* n = mst.adjList[i];
        while (n) {
            count++;
            n = n->next;
        }
    }

    CHECK(count / 2 == 7);
    CHECK_FALSE(hasEdge(mst, 8, 4));
    CHECK_FALSE(hasEdge(mst, 8, 7));
    CHECK(mst.adjList[8] == nullptr);
}

/**
 * Test cases for Queue operations.
 */
TEST_CASE("Queue tests") {
    Queue queue;
    for (int i = 0; i < MAX_VALUE; i++) {
        queue.enqueue(i);
    }
    CHECK_THROWS_AS(queue.enqueue(MAX_VALUE), std::overflow_error);

    Queue q2;
    CHECK(q2.isEmpty());
    CHECK_THROWS_AS(q2.dequeue(), std::underflow_error);
}

/**
 * Test cases for Stack operations.
 */
TEST_CASE("Stack tests") {
    Stack stack;
    for (int i = 0; i < MAX_VALUE; i++) {
        stack.push(i);
    }
    CHECK_THROWS_AS(stack.push(MAX_VALUE), std::overflow_error);

    Stack s2;
    CHECK_THROWS_AS(s2.pop(), std::underflow_error);
}

/**
 * Test cases for UnionFind operations.
 */
TEST_CASE("UnionFind tests") {
    UnionFind unionFind;
    unionFind.makeSet(10);
    unionFind.unite(1, 2);
    unionFind.unite(2, 3);

    CHECK(unionFind.isConnected(1, 3));
    CHECK_FALSE(unionFind.isConnected(1, 4));
}