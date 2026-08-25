// Depth First Search (DFS) Traversal Algorithm Implementation In C++
#include<iostream>
#include<vector>
#include<list>

using namespace std;

// Graph Class
class Graph {
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
    Graph g(7); // Create a graph with 7 vertices

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    // Print the adjacency list
    g.printAdjList();

    return 0;
};

