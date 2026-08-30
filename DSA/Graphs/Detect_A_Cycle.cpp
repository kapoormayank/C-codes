// Detect a cycle in a directed graph using DFS Algorithm Implementation In C++
#include <iostream>
#include <vector>
#include <list>
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

    // Function to add an edge to the graph undirected
    void addEdge(int u, int v) {
        adj[u].push_back(v); // Add v to u’s list.
        adj[v].push_back(u); // Add u to v’s list (for undirected graph)
    }

    // Function to perform DFS traversal of the graph and detect a cycle
    bool dfsCyclic(int v,vector<bool>& visited, vector<bool>& recStack) {
        if(recStack[v]) {
            return true; // Cycle detected
        }

        if(visited[v]) {
            return false; // Already visited
        }

        visited[v] = true; // Mark the current vertex as visited
        recStack[v] = true;

        for(int neighbor : adj[v]) {
            if(dfsCyclic(neighbor,visited,recStack)){
                return true;
            }
        }

        recStack[v] = false;
        return false;
    }

    // Function to check if graph contains a cycle
    bool isCyclic() {

        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        // Check every vertex because graph
        // can be disconnected
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfsCyclic(i, visited, recStack)) {
                    return true;
                }
            }
        }

        return false;
    }

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

    // Create a graph with 5 vertices
    Graph g(5);

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    // Print adjacency list
    cout << "Graph representation:\n";
    g.printAdjList();

    // Check cycle
    if (g.isCyclic()) {
        cout << "\nGraph contains a cycle." << endl;
    } else {
        cout << "\nGraph does not contain a cycle." << endl;
    }

    return 0;
}

