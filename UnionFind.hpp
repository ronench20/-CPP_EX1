//ronen.chereshn@msmail.ariel.ac.il

#ifndef CPP_EX1_UNIONFIND_HPP
#define CPP_EX1_UNIONFIND_HPP
#define MAX_VALUE 1024

/**
 * Class to represent the Union-Find data structure (Disjoint Set Union).
 */
class UnionFind {
private:
    int parent[MAX_VALUE]; ///< Array to store the parent of each element.
    int rank[MAX_VALUE]; ///< Array to store the rank (approximate tree height) of each element.

public:
    /**
     * Constructs a UnionFind object and initializes the parent and rank arrays.
     */
    UnionFind();

    /**
     * Initializes the parent and rank arrays for a given number of vertices.
     *
     * @param numOfVertices The number of vertices to initialize.
     */
    void makeSet(int numOfVertices);

    /**
     * Finds the representative (root) of the set containing element u.
     *
     * @param u The element to find the set representative for.
     * @return The representative of the set containing u.
     */
    int find(int u);

    /**
     * Unites the sets containing elements u and v.
     *
     * @param u The first element.
     * @param v The second element.
     */
    void unite(int u, int v);

    /**
     * Checks if elements u and v are in the same set.
     *
     * @param u The first element.
     * @param v The second element.
     * @return true if u and v are in the same set, false otherwise.
     */
    bool isConnected(int u, int v);
};

#endif //CPP_EX1_UNIONFIND_HPP