// Reference: https://leetcode.com/problems/spiral-matrix/



// Given an m x n matrix, return all elements of the matrix in spiral order.

 

// Example 1:
// ==========
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]

// Example 2:
// ==========
// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 


// Constraints:
// ============
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100





class Solution {
public:
    void moveRight(int &left, int &right, int &top, int &bottom, vector<vector<int>> &matrix, vector<int> &res) {
        for (int col = left; col <= right; ++col)
            res.push_back(matrix[top][col]);
        ++top;
    }

    void moveDown(int &left, int &right, int &top, int &bottom, vector<vector<int>> &matrix, vector<int> &res) {
        for (int row = top; row <= bottom; ++row)
            res.push_back(matrix[row][right]);
        --right;
    }

    void moveLeft(int &left, int &right, int &top, int &bottom, vector<vector<int>> &matrix, vector<int> &res) {
        if (top <= bottom) {
            for (int col = right; col >= left; --col)
                res.push_back(matrix[bottom][col]);
            --bottom;
        }
    }

    void moveUp(int &left, int &right, int &top, int &bottom, vector<vector<int>> &matrix, vector<int> &res) {
        if (left <= right) {
            for (int row = bottom; row >= top; --row)
                res.push_back(matrix[row][left]);
            ++left;
        }
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return {};
        vector<int> res;
        int row = matrix.size(), col = matrix[0].size();
        int left = 0, right = col-1;
        int top = 0, bottom = row-1;
        while (left <= right && top <= bottom) {
            moveRight(left, right, top, bottom, matrix, res);
            moveDown(left, right, top, bottom, matrix, res);
            moveLeft(left, right, top, bottom, matrix, res);
            moveUp(left, right, top, bottom, matrix, res);
        }
        return res;
    }
};
