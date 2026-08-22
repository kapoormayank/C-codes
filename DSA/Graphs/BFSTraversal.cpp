// Breadth First Search (BFS) Traversal Algorithm Implementation In C++
#include<iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;

// Graph Class
class Graph {

    // Data Members
    int V; // Number of vertices
    list<int>* l;

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

    // Function to perform BFS traversal of the graph
    void bfs() {
        queue<int> Q;
        vector<bool> visited(V, false);

        Q.push(0); // Start BFS from vertex 0
        visited[0] = true;

        while(Q.size() > 0) {
            int u = Q.front();
            Q.pop();
            cout << u << " ";

            for(int v : l[u]) {
                if(!visited[v]) {
                    Q.push(v);
                    visited[v] = true;
                }
            }
        }
        cout << endl;
    }
};

// Main function
int main() {
    // Create a graph with 5 vertices
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    cout << "Adjacency List of the Graph:" << endl;
    g.printAdjList();

    cout << "\nBFS Traversal of the Graph: " ;
    g.bfs();
    return 0;
}
