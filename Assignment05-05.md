# Assignment 05-05

## Aim
To implement an undirected graph using adjacency list representation and perform BFS (Breadth-First Search) and DFS (Depth-First Search) traversals.

## Steps Followed
1. Defined a `Graph` class with:
   - Number of vertices.
   - Adjacency list to represent edges.
2. Implemented `addEdge` method to add undirected edges.
3. Implemented BFS traversal:
   - Used a queue and visited vector.
   - Print nodes in order of visitation starting from given node.
4. Implemented DFS traversal:
   - Used recursion and visited vector.
   - Print nodes in DFS order starting from given node.
5. Implemented `displayList` to print adjacency list of the graph.
6. Supported user input for vertices, edges, and edges details.
7. Provided user input for starting vertex for traversals.
8. Displayed adjacency list followed by BFS and DFS traversal outputs.

## Code
```cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adjList;

public:
    Graph(int vertices) : V(vertices), adjList(vertices) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Undirected graph
    }

    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            for (int v : adjList[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }

    void DFSUtil(int u, vector<bool>& visited) {
        visited[u] = true;
        cout << u << " ";

        for (int v : adjList[u]) {
            if (!visited[v]) {
                DFSUtil(v, visited);
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }

    void displayList() {
        cout << "Adjacency List:" << endl;
        for (int i = 0; i < V; ++i) {
            cout << i << ": ";
            for (int v : adjList[i]) {
                cout << v << " ";
            }
            cout << endl;
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

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.displayList();

    int start;
    cout << "Enter starting vertex for traversals: ";
    cin >> start;

    g.BFS(start);
    g.DFS(start);

    return 0;
}
```

## Output (Sample)
```
Enter number of vertices: 5
Enter number of edges: 4
Enter edges (u v):
0 1
1 2
2 3
3 4
Adjacency List:
0: 1 
1: 0 2 
2: 1 3 
3: 2 4 
4: 3 
Enter starting vertex for traversals: 0
BFS Traversal: 0 1 2 3 4 
DFS Traversal: 0 1 2 3 4
