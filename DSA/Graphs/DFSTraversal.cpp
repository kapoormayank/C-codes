// Depth First Search (DFS) Traversal Algorithm Implementation In C++
#include<iostream>
#include<vector>
#include<list>

using namespace std;

// Graph Class
class Graph {

    // Data Members
    int V; // Number of vertices
    list<int>* l; // Adjacency list

    // Public Access Specifier
    public:

    // Parameterized Constructor
    Graph(int v) {
        this->V = v;
        l = new list<int>[V];
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u); // For undirected graph
    }

    // Function to perform DFS traversal of the graph
    void dfs(int start,vector<bool>& visited) { 
        
        // O(V + E) Time Complexity

        cout << start << " "; // Print the current vertex
        visited[start] = true; // Mark the current vertex as visited

        // Recur for all the vertices adjacent to this vertex
        for (int x : l[start]) {
            if (!visited[x]) {
                dfs(x, visited);
            }
        }
    }

    // Print the adjacency list of the graph
    void printAdjList() {
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": ";
            for (int x : l[i]) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
};

// Main function
int main() {
    // Create a graph with 5 vertices
    Graph g(5);

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    // Print the adjacency list
    g.printAdjList();

    // Perform DFS traversal
    cout << "DFS Traversal starting from vertex 0: ";
    vector<bool> visited(5, false);
    g.dfs(0, visited);

    return 0;
};

