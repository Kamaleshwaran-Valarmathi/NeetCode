// Reference: https://leetcode.com/problems/rotting-oranges/



// You are given an m x n grid where each cell can have one of three values:

// - 0 representing an empty cell,
// - 1 representing a fresh orange, or
// - 2 representing a rotten orange.

// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes 
// rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If 
// this is impossible, return -1.

 

// Example 1:
// ==========
// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4

// Example 2:
// ==========
// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, 
//      because rotting only happens 4-directionally.

// Example 3:
// ==========
// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 


// Constraints:
// ============
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 10
// grid[i][j] is 0, 1, or 2.





class Solution {
public:
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool isValidPos(vector<vector<int>> &grid, int r, int c) {
        return (r >= 0 && r < grid.size()) && (c >= 0 && c < grid[0].size());
    }

    bool isAllRotten(vector<vector<int>> &grid) {
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                if (grid[i][j] == 1)
                    return false;
        return true;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int mins = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                if (grid[i][j] == 2)
                    q.push({i, j});
        while (!q.empty()) {
            for (int i = 0, sz = q.size(); i < sz; ++i) {
                pair<int, int> curPos = q.front();
                q.pop();
                for (int j = 0; j < dir.size(); ++j) {
                    int nextRow = curPos.first + dir[j].first;
                    int nextCol = curPos.second + dir[j].second;
                    if (isValidPos(grid, nextRow, nextCol) && grid[nextRow][nextCol] == 1) {
                        grid[nextRow][nextCol] = 2;
                        q.push({nextRow, nextCol});
                    }
                }
            }
            if (!q.empty())
                ++mins;
        }
        return isAllRotten(grid) ? mins : -1;
    }
};
