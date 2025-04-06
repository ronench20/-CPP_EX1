//ronen.chereshn@msmail.ariel.ac.il

#ifndef CPP_EX1_GRAPH_HPP
#define CPP_EX1_GRAPH_HPP

namespace graph{
    /**
     * Structure to represent a node in the adjacency list.
     */
    struct Node {
        int vertex; ///< The vertex number.
        int weight; ///< The weight of the edge.
        Node *next; ///< Pointer to the next node in the adjacency list.
    };

    /**
     *Class to represent a graph using an adjacency list.
     */
    class Graph {
    private:
        int numOfVertices; ///< The number of vertices in the graph.

    public:
        Node **adjList; ///< Pointer to an array of adjacency lists.

        /**
         * Constructs a Graph object with a specified number of vertices.
         *
         * @param vertices The number of vertices in the graph.
         */
        Graph(int vertices);

        /**
         *Destructor for the Graph class.
         *
         * Deallocates memory used for the adjacency list.
         */
        ~Graph();

        /**
         * Adds an edge to the graph.
         *
         * @param src The source vertex.
         * @param dest The destination vertex.
         * @param weight The weight of the edge. Default is 1.
         * @throws std::invalid_argument if the source or destination vertex is invalid.
         */
        void addEdge(int src, int dest, int weight = 1);

        /**
         * Removes an edge from the graph.
         *
         * @param src The source vertex.
         * @param dest The destination vertex.
         * @throws std::invalid_argument if the source or destination vertex is invalid.
         */
        void removeEdge(int src, int dest);

        /**
         *Prints the graph to the standard output.
         *
         * Displays each vertex and its adjacent vertices with edge weights.
         */
        void printGraph();

        /**
         *Gets the number of vertices in the graph.
         *
         * @return The number of vertices.
         */
        int getNumOfVertices() const;
    };

}

#endif //CPP_EX1_GRAPH_HPP