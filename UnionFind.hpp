//ronen.chereshn@msmail.ariel.ac.il

#ifndef CPP_EX1_UNIONFIND_HPP
#define CPP_EX1_UNIONFIND_HPP
#define MAX_VALUE 1024

class UnionFind{
private:
    int parent[MAX_VALUE];
    int rank[MAX_VALUE];

public:
    UnionFind();
    void makeSet(int numOfVertices);
    int find(int u);
    void unite(int u, int v);
    bool isConnected(int u, int v);
};


#endif //CPP_EX1_UNIONFIND_HPP
