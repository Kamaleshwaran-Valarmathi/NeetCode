// Reference: https://leetcode.com/problems/pascals-triangle-ii/



// Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

 

// Example 1:
// ==========
// Input: rowIndex = 3
// Output: [1,3,3,1]

// Example 2:
// ==========
// Input: rowIndex = 0
// Output: [1]

// Example 3:
// ==========
// Input: rowIndex = 1
// Output: [1,1]
 


// Constraints:
// ============
// 0 <= rowIndex <= 33



// Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?
 




class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1, 1);
        long curNcR = 1;
        for (int i = 1; i < rowIndex; ++i) {
            curNcR *= (rowIndex + 1 - i);
            curNcR /= i;
            res[i] = curNcR;
        }
        return res;
    }
};
