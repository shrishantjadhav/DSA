# Assignment 05-02

## Aim
To implement Prim's Minimum Spanning Tree (MST) algorithm for an undirected weighted graph using adjacency list representation.

## Steps Followed
1. Defined a `Graph` class with:
   - Number of vertices.
   - Adjacency list with pairs of vertex and edge weight.
2. Implemented `addEdge` method to add undirected edges with weights.
3. Implemented Prim's MST algorithm:
   - Used a priority queue to pick minimum weight edge each step.
   - Tracked which vertices included in the MST.
   - Updated parent and key arrays to build the MST.
4. Printed the edges included in the MST with their weights.
5. User inputs for graph vertices, edges, and edges details with weights.
6. Output MST edges after running the algorithm.

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
        adjList[v].push_back({u, w});
    }

    void primMST() {
        vector<int> key(V, INT_MAX);
        vector<bool> inMST(V, false);
        vector<int> parent(V, -1);
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        key[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u]) continue;
            inMST[u] = true;

            for (auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                    pq.push({key[v], v});
                }
            }
        }

        cout << "Minimum Spanning Tree:" << endl;
        for (int i = 1; i < V; ++i) {
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
0 - 3 : 6
1 - 4 : 5
