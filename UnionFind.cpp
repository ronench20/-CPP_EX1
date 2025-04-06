//ronen.chereshn@msmail.ariel.ac.il

#include "UnionFind.hpp"

/**
 * Constructs a UnionFind object and initializes the parent and rank arrays.
 */
UnionFind::UnionFind() {
    for (int i = 0; i < MAX_VALUE; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }
}

/**
 * Initializes the parent and rank arrays for a given number of vertices.
 *
 * @param numOfVertices The number of vertices to initialize.
 */
void UnionFind::makeSet(int numOfVertices) {
    for (int i = 0; i < numOfVertices; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }
}

/**
 * Finds the representative (root) of the set containing element u.
 *
 * @param u The element to find the set representative for.
 * @return The representative of the set containing u.
 */
int UnionFind::find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

/**
 * Unites the sets containing elements u and v.
 *
 * @param u The first element.
 * @param v The second element.
 */
void UnionFind::unite(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);

    if (rootU != rootV) {
        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

/**
 * Checks if elements u and v are in the same set.
 *
 * @param u The first element.
 * @param v The second element.
 * @return true if u and v are in the same set, false otherwise.
 */
bool UnionFind::isConnected(int u, int v) {
    return find(u) == find(v);
}