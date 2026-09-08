// Rotting Oranges Algorithm Implementation In C++
#include <iostream>
#include <vector>

using namespace std;

// Graph Class
class Graph {

    // Public Specifier
    public: 
    int countRottenOrganes(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        queue<pair<int, int>> queue;
        queue.push({0, 0}); // Start from the first cell (0, 0)
        visited[0][0] = true;

        while (queue.size() > 0) {
            int u = queue.pop();
            for(int neighbor: grid[u]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.push(neighbor);
                }
            }
        }

        return -1;
    }
};

// Main function
int main() {
    // Define a 2D grid representing the oranges
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    // Create an instance of the Graph class
    Graph g;

    // Call the function to calculate the time taken for all oranges to rot
    // (Function implementation is not provided in this snippet)
    
    return 0;
}
