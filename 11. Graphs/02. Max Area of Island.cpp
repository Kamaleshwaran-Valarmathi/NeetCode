// Reference: https://leetcode.com/problems/max-area-of-island/



// You are given an m x n binary matrix grid. An island is a group of 1's (representing land) 
// connected 4-directionally (horizontal or vertical.) You may assume all four edges of the 
// grid are surrounded by water.

// The area of an island is the number of cells with a value 1 in the island.

// Return the maximum area of an island in grid. If there is no island, return 0.

 

// Example 1:
// ==========
// Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
// Output: 6
// Explanation: The answer is not 11, because the island must be connected 4-directionally.

// Example 2:
// ==========
// Input: grid = [[0,0,0,0,0,0,0,0]]
// Output: 0
 


// Constraints:
// ============
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 50
// grid[i][j] is either 0 or 1.





class Solution {
public:
    vector<int> X = {0, 0, 1, -1};
    vector<int> Y = {1, -1, 0, 0};

    bool isValid(int x, int y, int row, int col) {
        return (x >= 0 && x < row && y >= 0 && y < col);
    }

    void dfs(int& curArea, int x, int y, int row, int col, vector<vector<int>>& grid) {
        grid[x][y] = 0;
        ++curArea;
        for (int i = 0; i < X.size(); ++i) {
            int nextX = x + X[i], nextY = y + Y[i];
            if (isValid(nextX, nextY, row, col) && grid[nextX][nextY] == 1)
                dfs(curArea, nextX, nextY, row, col, grid);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0, row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1) {
                    int curArea = 0;
                    dfs(curArea, i, j, row, col, grid);
                    maxArea = max(maxArea, curArea);
                }
            }
        }
        return maxArea;
    }
};
