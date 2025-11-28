# Assignment 05-04

## Aim
To implement Dijkstra's shortest path algorithm on a directed, weighted graph using adjacency list representation.

## Steps Followed
1. Defined a `Graph` class with:
   - Number of vertices.
   - Adjacency list storing pairs of connected vertex and edge weight.
2. Implemented `addEdge` method to add a directed edge with weight.
3. Implemented Dijkstra's algorithm:
   - Used a priority queue to store minimum distances.
   - Updated shortest path distances to each vertex from a source vertex.
4. Provided inputs for number of vertices, edges, and edge details.
5. Took source and destination vertices for shortest path query.
6. Displayed shortest distance or message if no path exists.

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
        // adjList[v].push_back({u, w}); // Uncomment for undirected graph
    }

    void dijkstra(int src, int dest) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        if (dist[dest] == INT_MAX) {
            cout << "No path from " << src << " to " << dest << endl;
        } else {
            cout << "Shortest distance from " << src << " to " << dest << " is " << dist[dest] << endl;
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

    int src, dest;
    cout << "Enter source node: ";
    cin >> src;
    cout << "Enter destination node: ";
    cin >> dest;

    g.dijkstra(src, dest);

    return 0;
}
```

## Output (Sample)
```
Enter number of vertices: 5
Enter number of edges: 7
Enter edges (u v w):
0 1 4
0 2 1
2 1 2
1 3 1
2 3 5
3 4 3
1 4 7
Enter source node: 0
Enter destination node: 4
Shortest distance from 0 to 4 is 8
