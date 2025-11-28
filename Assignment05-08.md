# Assignment 05-08

## Aim
To implement Prim's Minimum Spanning Tree (MST) algorithm on an undirected weighted graph using adjacency list representation.

## Steps Followed
1. Created a `Graph` class containing:
   - Number of vertices.
   - Adjacency list storing connected vertices and edge weights.
2. Implemented `addEdge` function to add bidirectional edges.
3. Used Prim's MST algorithm using:
   - Priority queue to pick edges with minimum weight.
   - Arrays to store keys, parents, and MST inclusion status.
4. Started from vertex 0 and included edges to MST with smallest weights.
5. Printed all edges included in MST with their weights.
6. Supported user input of vertices, edges, and edge information.
7. Displayed the MST edges after algorithm completion.

## Code
```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

class Graph {
private:
    int V;
    vector<vector<pii>> adjList;

public:
    Graph(int vertices) : V(vertices), adjList(vertices) {}

    void addEdge(int u, int v, int w) {
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w}); // undirected graph
    }

    void primMST() {
        vector<int> key(V, INT_MAX);
        vector<int> parent(V, -1);
        vector<bool> inMST(V, false);
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        key[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            inMST[u] = true;

            for (auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.push({key[v], v});
                    parent[v] = u;
                }
            }
        }

        cout << "Edges in MST:" << endl;
        for (int i = 1; i < V; i++) {
            cout << parent[i] << " - " << i << " : " << key[i] << endl;
        }
    }
};

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

    g.primMST();

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
Edges in MST:
2 - 3 : 4
0 - 3 : 5
0 - 1 : 10
