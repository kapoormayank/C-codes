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

    // Parameterized Constructor
    Graph(int v) {
        this->V = v;
        l = new list<int>[V];
    }
};

// Main function
int main() {
    return 0;
}

