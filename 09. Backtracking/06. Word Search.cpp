// Reference: https://leetcode.com/problems/word-search/



// Given an m x n grid of characters board and a string word, return true if word exists in 
// the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent 
// cells are horizontally or vertically neighboring. The same letter cell may not be used more 
// than once.

 

// Example 1:
// ==========
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true

// Example 2:
// ==========
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// Output: true

// Example 3:
// ==========
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// Output: false
 


// Constraints:
// ============
// m == board.length
// n = board[i].length
// 1 <= m, n <= 6
// 1 <= word.length <= 15
// board and word consists of only lowercase and uppercase English letters.
 


// Follow up: Could you use search pruning to make your solution faster with a larger board?





class Solution {
public:
    vector<int> X = {0, 0, -1, 1};
    vector<int> Y = {-1, 1, 0, 0};

    bool isValid(int x, int y, int row, int col) {
        return (x >= 0 && x < row && y >= 0 && y < col);
    }

    bool dfs(int x, int y, int wordIdx, int row, int col, vector<vector<char>>& board, string& word, vector<vector<bool>>& visited) {
        if (board[x][y] != word[wordIdx])
            return false;
        if (wordIdx == word.size()-1)
            return true;
        for (int i = 0; i < X.size(); ++i) {
            int nextX = x + X[i], nextY = y + Y[i];
            if (isValid(nextX, nextY, row, col) && !visited[nextX][nextY]) {
                visited[nextX][nextY] = true;
                if (dfs(nextX, nextY, wordIdx+1, row, col, board, word, visited))
                    return true;
                visited[nextX][nextY] = false;
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string& word) {
        int row = board.size(), col = board[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                vector<vector<bool>> visited(row, vector<bool>(col, false));
                visited[i][j] = true;
                if (dfs(i, j, 0, row, col, board, word, visited))
                    return true;
            }
        }
        return false;
    }
};
