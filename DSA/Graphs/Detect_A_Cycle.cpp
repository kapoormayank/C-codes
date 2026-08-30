// Detect a cycle in a directed graph using DFS Algorithm Implementation In C++
#include <iostream>
using namespace std;

// Class to represent a directed graph
class Graph {
    int V; // Number of vertices
    list<int>* adj; // Adjacency list
    
    public:
    
    // Parameterized Constructor
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        adj[u].push_back(v); // Add v to u’s list.
        adj[v].push_back(u); // Add u to v’s list (for undirected graph)
    }

    bool isCyclic();

    // Print the adjacency list of the graph
    void printAdjList() {
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": ";
            for (int x : adj[i]) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
};

// Main function
int main() {
    return 0;
}

