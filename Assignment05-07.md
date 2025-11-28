# Assignment 05-07

## Aim
To implement Dijkstra's Shortest Path algorithm for a directed weighted graph using adjacency matrix representation.

## Steps Followed
1. Created a `dijkstra` function which takes:
   - Number of vertices `V`.
   - Adjacency matrix representing the graph.
   - Source vertex `src` and destination vertex `dest`.
2. Used a priority queue to hold vertices and their distance values.
3. Initialized all distances to infinity except the source.
4. Iterated to update the shortest distances to all vertices.
5. Checked and printed the shortest distance from source to destination or no path found.
6. Input graph parameters from user: number of vertices, edges, edges with weights.
7. Input source and destination nodes for shortest path.
8. Called the `dijkstra` function and displayed the shortest path distance.

## Code
```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

void dijkstra(int V, vector<vector<int>>& adjMatrix, int src, int dest) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < V; ++v) {
            if (adjMatrix[u][v] != 0 && adjMatrix[u][v] != INT_MAX) {
                int weight = adjMatrix[u][v];
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    if (dist[dest] == INT_MAX) {
        cout << "No path from " << src << " to " << dest << endl;
    } else {
        cout << "Shortest distance from " << src << " to " << dest << " is " << dist[dest] << endl;
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
        // adjMatrix[v][u] = w; // Uncomment for undirected graph
    }

    int src, dest;
    cout << "Enter source node: ";
    cin >> src;
    cout << "Enter destination node: ";
    cin >> dest;

    dijkstra(V, adjMatrix, src, dest);

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
