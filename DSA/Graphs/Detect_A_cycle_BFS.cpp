// Detect a cycle in a directed graph using BFS Algorithm Implementation In C++
#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

// Class to represent a directed graph
class Graph {
    int V;          // Number of vertices
    list<int> *adj; // Adjacency list

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

    // Function to perform BFS traversal of the graph and detect a cycle
    bool bfsCyclic(int v, vector<bool> &visited) {
        visited[v] = true;
        queue<int> q;
        q.push(v);

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
                else
                {
                    return true;
                }
            }
        }

        return false;
    }

    // Function to check if graph contains a cycle
    bool isCyclic() {

        vector<bool> visited(V, false);

        // Check every vertex because graph
        // can be disconnected
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (bfsCyclic(i, visited))
                {
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
int main(){

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
    }
    else
    {
        cout << "\nGraph does not contain a cycle." << endl;
    }

    return 0;
}
