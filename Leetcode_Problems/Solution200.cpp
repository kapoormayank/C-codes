// Leetcode Problem 200: Number of Islands
#include <iostream>
#include <vector>
using namespace std;

// Class to represent a directed graph
class Graph
{

public:
    // Island counting function using DFS
    int countIslands(vector<vector<int>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int count = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 1 && !visited[i][j])
                {
                    dfs(grid, visited, i, j);
                    count++;
                }
            }
        }
        return count;
    }

    // Depth First Search to mark all connected land cells
    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        // Check for out of bounds or water or already visited
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == 0 || visited[i][j])
        {
            return;
        }

        // Mark the cell as visited
        visited[i][j] = true;

        // Explore all 8 directions
        dfs(grid, visited, i - 1, j); // Up
        dfs(grid, visited, i + 1, j); // Down
        dfs(grid, visited, i, j - 1); // Left
        dfs(grid, visited, i, j + 1); // Right
    }
};

// Main function
int main()
{

    // Define a 2D grid representing the map
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1}};

    // Create a graph object
    Graph g;

    // Count the number of islands in the grid
    int numberOfIslands = g.countIslands(grid);
    // Print the number of islands
    cout << "Number of islands: " << numberOfIslands << endl;

    return 0;
}
