// Reference: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/



// Given an m x n integers matrix, return the length of the longest increasing path in matrix.

// From each cell, you can either move in four directions: left, right, up, or down. You may 
// not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

 

// Example 1:
// ==========
// Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
// Output: 4
// Explanation: The longest increasing path is [1, 2, 6, 9].

// Example 2:
// ==========
// Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
// Output: 4
// Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

// Example 3:
// ==========
// Input: matrix = [[1]]
// Output: 1
 


// Constraints:
// ============
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 200
// 0 <= matrix[i][j] <= 2^31 - 1





class Solution {
public:
    vector<int> X = {0, 0, -1, 1};
    vector<int> Y = {-1, 1, 0, 0};

    bool isValid(int x, int y, int n, int m) {
        return (x >= 0 && x < n) && (y >= 0 && y < m);
    }

    int dfs(int x, int y, int n, int m, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (dp[x][y] != -1)
            return dp[x][y];
        int res = 0;
        for (int i = 0; i < X.size(); ++i) {
            int nextX = x + X[i], nextY = y + Y[i];
            if (isValid(nextX, nextY, n, m) && matrix[x][y] < matrix[nextX][nextY])
                res = max(res, dfs(nextX, nextY, n, m, matrix, dp));
        }
        return dp[x][y] = res + 1;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res = -1, n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                res = max(res, dfs(i, j, n, m, matrix, dp));
        return res;
    }
};
