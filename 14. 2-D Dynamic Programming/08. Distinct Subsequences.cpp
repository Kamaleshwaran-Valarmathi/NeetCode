// Reference: https://leetcode.com/problems/distinct-subsequences/



// Given two strings s and t, return the number of distinct subsequences of s which equals t.
// The test cases are generated so that the answer fits on a 32-bit signed integer.

 

// Example 1:
// ==========
// Input: s = "rabbbit", t = "rabbit"
// Output: 3
// Explanation:
// As shown below, there are 3 ways you can generate "rabbit" from s.
// rabbbit
// rabbbit
// rabbbit

// Example 2:
// ==========
// Input: s = "babgbag", t = "bag"
// Output: 5
// Explanation:
// As shown below, there are 5 ways you can generate "bag" from s.
// babgbag
// babgbag
// babgbag
// babgbag
// babgbag
 


// Constraints:
// ============
// 1 <= s.length, t.length <= 1000
// s and t consist of English letters





class Solution {
public:
    int helper(int sIdx, int tIdx, string& s, string& t, vector<vector<int>>& dp) {
        if (tIdx >= t.size())       return 1;
        if (sIdx >= s.size())       return 0;
        if (dp[sIdx][tIdx] != -1)   return dp[sIdx][tIdx];
        int res = helper(sIdx+1, tIdx, s, t, dp);
        if (s[sIdx] == t[tIdx])
            res += helper(sIdx+1, tIdx+1, s, t, dp);
        return dp[sIdx][tIdx] = res;
    }

    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(0, 0, s, t, dp);
    }
};
