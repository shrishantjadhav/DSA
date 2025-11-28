# Assignment 05-03

## Aim
To implement Kruskal's Minimum Spanning Tree (MST) algorithm on an undirected weighted graph using adjacency list representation and Union-Find data structure.

## Steps Followed
1. Defined an `Edge` structure for graph edges with comparison based on weight.
2. Implemented a `Graph` class with:
   - Number of vertices.
   - Adjacency list storing connected vertices and edge weights.
   - Methods to add edges and get all edges.
3. Implemented a `UnionFind` (Disjoint Set Union) class with:
   - Parent and rank arrays.
   - Methods `find` with path compression, and `unite` with union by rank.
4. Implemented Kruskal's MST algorithm:
   - Retrieved edges, sorted by weight.
   - Added edges to MST ensuring no cycles using Union-Find.
5. Printed edges in MST with their weights.
6. Supported user input for vertices, edges, and edge details.
7. Displayed the MST edges after computation.

## Code
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class Graph {
private:
    int V;
    vector<vector<pair<int, int>>> adjList;

public:
    Graph(int vertices) : V(vertices), adjList(vertices) {}

    void addEdge(int u, int v, int w) {
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    vector<Edge> getEdges() {
        vector<Edge> edges;
        for (int u = 0; u < V; ++u) {
            for (auto& p : adjList[u]) {
                int v = p.first;
                int w = p.second;
                if (u < v) { // to avoid duplicate edges
                    edges.push_back({u, v, w});
                }
            }
        }
        return edges;
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

void kruskalMST(Graph& g, int V) {
    vector<Edge> edges = g.getEdges();
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

    Graph g(V);

    cout << "Enter edges (u v w):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    kruskalMST(g, V);

    return 0;
}
```

## Output (Sample)
```
Enter number of vertices: 5
Enter number of edges: 7
Enter edges (u v w):
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7
3 4 9
Minimum Spanning Tree:
0 - 1 : 2
1 - 2 : 3
1 - 4 : 5
0 - 3 : 6
