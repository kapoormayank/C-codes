// Rotting Oranges Algorithm Implementation In C++
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Graph Class
class Graph {

    // Public Specifier
    public: 
    int countRottenOrganes(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        queue<pair<pair<int, int>,int>> queue;
        queue.push({{0, 0}, 0}); // Start from the first cell (0, 0) with time 0
        visited[0][0] = true;

        while (queue.size() > 0) {
            auto [cell, time] = queue.front();
            queue.pop();
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

    Graph g;

    int result = g.countRottenOranges(grid);

    cout << "Time taken: " << result << " minutes" << endl;

    return 0;
}
