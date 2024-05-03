// Reference: https://leetcode.com/problems/pascals-triangle/



// Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it.



// Example 1:
// ==========
// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

// Example 2:
// ==========
// Input: numRows = 1
// Output: [[1]]
 


// Constraints:
// ============
// 1 <= numRows <= 30





class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        for (int row = 0; row < numRows; ++row) {
            res[row].resize(row+1, 1);
            for (int col = 1; col < row; ++col) {
                res[row][col] = res[row-1][col-1] + res[row-1][col];
            }
        }
        return res;
    }
};
