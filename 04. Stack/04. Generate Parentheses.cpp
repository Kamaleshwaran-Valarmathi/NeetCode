// Reference: https://leetcode.com/problems/generate-parentheses/



// Given n pairs of parentheses, write a function to generate all combinations of well-formed 
// parentheses.

 

// Example 1:
// ==========
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]

// Example 2:
// ==========
// Input: n = 1
// Output: ["()"]
 


// Constraints:
// ============
// 1 <= n <= 8





class Solution {
public:
    void helper(int leftRem, int rightRem, string cur, vector<string> &res) {
        if (leftRem == 0 && rightRem == 0) {
            res.push_back(cur);
            return;
        }
        if (leftRem > 0)
            helper(leftRem-1, rightRem, cur + '(', res);
        if (rightRem > leftRem)
            helper(leftRem, rightRem-1, cur + ')', res);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(n, n, "", res);
        return res;
    }
};
