// Reference: https://leetcode.com/problems/surrounded-regions/



// Given an m x n matrix board containing 'X' and 'O', capture all regions that are 
// 4-directionally surrounded by 'X'.

// A region is captured by flipping all 'O's into 'X's in that surrounded region.

 

// Example 1:
// ==========
// Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
// Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
// Explanation: Notice that an 'O' should not be flipped if:
// - It is on the border, or
// - It is adjacent to an 'O' that should not be flipped.
// The bottom 'O' is on the border, so it is not flipped.
// The other three 'O' form a surrounded region, so they are flipped.

// Example 2:
// ==========
// Input: board = [["X"]]
// Output: [["X"]]
 


// Constraints:
// ============
// m == board.length
// n == board[i].length
// 1 <= m, n <= 200
// board[i][j] is 'X' or 'O'





class Solution {
public:
    vector<int> X = {0, 0, 1, -1};
    vector<int> Y = {1, -1, 0, 0};

    bool isValid(int x, int y, int row, int col) {
        return (x >= 0 && x < row) & (y >= 0 && y < col);
    }

    void dfs(vector<vector<char>>& board, int x, int y, int row, int col) {
        board[x][y] = '-';
        for (int i = 0; i < X.size(); ++i) {
            int nextX = x + X[i], nextY = y + Y[i];
            if (isValid(nextX, nextY, row, col) && board[nextX][nextY] == 'O')
                dfs(board, nextX, nextY, row, col);
        }
    }

    void solve(vector<vector<char>>& board) {
        int row = board.size(), col = board[0].size();
        for (int i = 0; i < row; ++i) {
            if (board[i][0] == 'O')     dfs(board, i, 0, row, col);
            if (board[i][col-1] == 'O') dfs(board, i, col-1, row, col);
        }
        for (int i = 0; i < col; ++i) {
            if (board[0][i] == 'O')     dfs(board, 0, i, row, col);
            if (board[row-1][i] == 'O') dfs(board, row-1, i, row, col);
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == '-')         board[i][j] = 'O';
                else if (board[i][j] == 'O')    board[i][j] = 'X';
            }
        }
    }
};
