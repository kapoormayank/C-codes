// Graph Algorithm Implementation In C++
#include<iostream>
#include<vector>
#include<list>

using namespace std;

// Graph Class
class Graph {

    // Data Members
    int V; // Number of vertices
    list<int>* l;

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

    // Function to print the adjacency list of the graph
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
    Graph g(5); // Create a graph with 5 vertices

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    cout << "Adjacency List of the Graph:" << endl;
    g.printAdjList();
    return 0;
}

