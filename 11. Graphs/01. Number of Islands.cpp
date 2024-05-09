// Reference: https://leetcode.com/problems/number-of-islands/



// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), 
// return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or 
// vertically. You may assume all four edges of the grid are all surrounded by water.

 

// Example 1:
// ==========
// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1

// Example 2:
// ==========
// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3
 


// Constraints:
// ============
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] is '0' or '1'.





class Solution {
public:
    vector<int> X = {0, 0, 1, -1};
    vector<int> Y = {1, -1, 0, 0};

    bool isValid(int row, int col, int R, int C, vector<vector<char>> &grid) {
        return (row >= 0 && row < R && col >= 0 && col < C && grid[row][col] == '1');
    }

    void dfs(int row, int col, int R, int C, vector<vector<char>> &grid) {
        grid[row][col] = '0';
        for (int i = 0; i < X.size(); ++i) {
            int nextRow = row + X[i];
            int nextCol = col + Y[i];
            if (isValid(nextRow, nextCol, R, C, grid))
                dfs(nextRow, nextCol, R, C, grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int islands = 0, R = grid.size(), C = grid[0].size();
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (grid[i][j] == '1') {
                    dfs(i, j, R, C, grid);
                    ++islands;
                }
            }
        }
        return islands;
    }
};
