# Assignment 05-01

## Aim
To implement an undirected graph using adjacency matrix representation and perform BFS (Breadth-First Search) and DFS (Depth-First Search) traversals.

## Steps Followed
1. Defined a `Graph` class with:
   - Number of vertices.
   - Adjacency matrix to represent edges.
2. Implemented `addEdge` method to add an undirected edge between two vertices.
3. Implemented BFS traversal:
   - Used a queue and visited array.
   - Started from a given starting vertex.
   - Printed nodes in order of visitation.
4. Implemented DFS traversal:
   - Used recursion and visited array.
   - Started from a given starting vertex.
   - Printed nodes in DFS order.
5. Implemented a method to display the adjacency matrix.
6. Created a menu to input graph details and edges, and perform BFS and DFS.
7. Provided appropriate user prompts and output.

## Code
```cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph 
{
    private:
        int V;
        vector<vector<int>> adjMatrix;

    public:
        Graph(int vertices) : V(vertices), adjMatrix(vertices, vector<int>(vertices, 0)) {}

        void addEdge(int u, int v) 
        {
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1; // Undirected graph
        }

        void BFS(int start) 
        {
            vector<bool> visited(V, false);
            queue<int> q;
            visited[start] = true;
            q.push(start);

            cout << "BFS Traversal: ";
            while (!q.empty()) 
            {
                int u = q.front();
                q.pop();
                cout << u << " ";

                for (int v = 0; v < V; ++v) 
                {
                    if (adjMatrix[u][v] && !visited[v]) 
                    {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
            
        cout << endl;
        }

    void DFSUtil(int u, vector<bool>& visited) 
    {
        visited[u] = true;
        cout << u << " ";

        for (int v = 0; v < V; ++v) 
        {
            if (adjMatrix[u][v] && !visited[v]) 
            {
                DFSUtil(v, visited);
            }
        }
    }

    void DFS(int start) 
    {
        vector<bool> visited(V, false);
        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }

    void displayMatrix() 
    {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < V; ++i) 
        {
            for (int j = 0; j < V; ++j) 
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() 
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    Graph g(V);

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; ++i) 
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.displayMatrix();

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
Adjacency Matrix:
0 1 0 0 0 
1 0 1 0 0 
0 1 0 1 0 
0 0 1 0 1 
0 0 0 1 0 
Enter starting vertex for traversals: 0
BFS Traversal: 0 1 2 3 4 
DFS Traversal: 0 1 2 3 4 
