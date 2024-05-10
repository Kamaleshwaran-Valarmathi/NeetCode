// Reference: https://leetcode.ca/all/286.html 



// You are given a m x n 2D grid initialized with these three possible values.

// - -1 - A wall or an obstacle.
// - 0 - A gate.
// - INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent 
//      INF as you may assume that the distance to a gate is less than 2147483647.

// Fill each empty room with the distance to its nearest gate. If it is impossible to reach a 
// gate, it should be filled with INF.



// Example: 
// ========
// Given the 2D grid:
// INF  -1  0  INF
// INF INF INF  -1
// INF  -1 INF  -1
//   0  -1 INF INF

// After running your function, the 2D grid should be:
//   3  -1   0   1
//   2   2   1  -1
//   1  -1   2  -1
//   0  -1   3   4





class Solution {
public:
    vector<int> X = {0, 0, 1, -1};
    vector<int> Y = {1, -1, 0, 0};

    bool isValid(int x, int y, int row, int col) {
        return (x >= 0 && x < row && y >= 0 && y < col);
    }

    void wallsAndGates(vector<vector<int>>& rooms) {
        int row = rooms.size(), col = rooms[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (rooms[i][j] == 0)
                    q.push({i, j});
        int timeTaken = 1;
        while (!q.empty()) {
            for (int i = 0, sz = q.size(); i < sz; ++i) {
                auto [curRow, curCol] = q.front();
                q.pop();
                for (int i = 0; i < X.size(); ++i) {
                    int nextRow = curRow + X[i], nextCol = curCol + Y[i];
                    if (isValid(nextRow, nextCol, row, col) && rooms[nextRow][nextCol] == INT_MAX) {
                        rooms[nextRow][nextCol] = timeTaken;
                        q.push({nextRow, nextCol});
                    }
                }
            }
            ++timeTaken;
        }
    }
};
