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

    void addEdge(int v, int w) {
        adj[v].push_back(w); // Add w to v’s list.
    }
    
    bool isCyclic();
};

// Main function
int main() {
    return 0;
}

