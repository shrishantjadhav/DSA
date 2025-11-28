# Assignment 05-06

## Aim
To implement Kruskal's Minimum Spanning Tree (MST) algorithm using an adjacency matrix representation for an undirected weighted graph.

## Steps Followed
1. Defined an `Edge` structure for graph edges with comparison based on weight.
2. Developed a `UnionFind` class to manage disjoint sets with path compression and union by rank.
3. Input graph details: number of vertices, number of edges, and each edge with weight.
4. Represented the graph as an adjacency matrix initialized with zeros.
5. Populated adjacency matrix with edge weights.
6. Extracted edges from the upper triangle of adjacency matrix to avoid duplicates.
7. Sorted edges based on weight.
8. Used Union-Find to pick edges ensuring no cycles in MST.
9. Printed the edges that constitute the MST along with their weights.

## Code
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class UnionFind {
private:
    vector<int> parent, rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        if (rank[px] < rank[py]) parent[px] = py;
        else if (rank[px] > rank[py]) parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
        return true;
    }
};

void kruskalMST(int V, vector<vector<int>>& adjMatrix) {
    vector<Edge> edges;
    for (int i = 0; i < V; ++i) {
        for (int j = i + 1; j < V; ++j) {
            if (adjMatrix[i][j] != 0 && adjMatrix[i][j] != INT_MAX) {
                edges.push_back({i, j, adjMatrix[i][j]});
            }
        }
    }

    sort(edges.begin(), edges.end());

    UnionFind uf(V);
    vector<Edge> mst;

    for (auto& e : edges) {
        if (uf.unite(e.u, e.v)) {
            mst.push_back(e);
        }
    }

    cout << "Minimum Spanning Tree:" << endl;
    for (auto& e : mst) {
        cout << e.u << " - " << e.v << " : " << e.weight << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adjMatrix(V, vector<int>(V, 0));

    cout << "Enter edges (u v w):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w; // Undirected
    }

    kruskalMST(V, adjMatrix);

    return 0;
}
```

## Output (Sample)
```
Enter number of vertices: 4
Enter number of edges: 5
Enter edges (u v w):
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
Minimum Spanning Tree:
2 - 3 : 4
0 - 3 : 5
0 - 1 : 10
