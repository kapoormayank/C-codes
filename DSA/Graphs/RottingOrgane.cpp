// Rotting Oranges Algorithm Implementation In C++
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Graph Class
class Graph {

    // Public Specifier
    public: 
    int organesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int ans = 0;

        // Create a visited matrix to keep track of visited cells
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        // Create a queue to perform BFS
        queue<pair<pair<int, int>,int>> queue;

        // Pushing all sources in the queue
       for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j] == 2) {
                    queue.push({{i, j}, 0});
                    visited[i][j] = true;
                }
            }
        }

        // BFS traversal to rot the oranges
        while(queue.size() > 0) {
            int i = queue.front().first.first;
            int j = queue.front().first.second;
            int time = queue.front().second;
            queue.pop();

            ans = max(ans, time);

            if (i-1 > 0 && !visited[i-1][j] && grid[i-1][j] == 1) {
                queue.push({{i-1, j}, time+1});
                visited[i-1][j] = true;
            }

            if (i+1 < rows && !visited[i+1][j] && grid[i+1][j] == 1) {
                queue.push({{i+1, j}, time+1});
                visited[i+1][j] = true;
            }

            if (j-1 > 0 && !visited[i][j-1] && grid[i][j-1] == 1) {
                queue.push({{i, j-1}, time+1});
                visited[i][j-1] = true;
            }

            if (j+1 < cols && !visited[i][j+1] && grid[i][j+1] == 1) {
                queue.push({{i, j+1}, time+1});
                visited[i][j+1] = true;
            }
        }
        
        return ans;
    }
};

// Main function
int main() {
    // Define a 2D grid representing the oranges
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {4, 1, 1}
    };

    // Create a Graph object
    Graph g;

    // Call the organesRotting function and store the result
    int result = g.organesRotting(grid);
    cout << "Time taken: " << result << " minutes" << endl;

    return 0;
}
