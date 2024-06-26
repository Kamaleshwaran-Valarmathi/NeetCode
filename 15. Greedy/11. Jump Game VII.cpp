// Reference: https://leetcode.com/problems/jump-game-vii/



// You are given a 0-indexed binary string s and two integers minJump and maxJump. In the 
// beginning, you are standing at index 0, which is equal to '0'. You can move from index i to 
// index j if the following conditions are fulfilled:
// - i + minJump <= j <= min(i + maxJump, s.length - 1), and
// - s[j] == '0'.

// Return true if you can reach index s.length - 1 in s, or false otherwise.

 

// Example 1:
// ==========
// Input: s = "011010", minJump = 2, maxJump = 3
// Output: true
// Explanation:
// In the first step, move from index 0 to index 3. 
// In the second step, move from index 3 to index 5.

// Example 2:
// ==========
// Input: s = "01101110", minJump = 2, maxJump = 3
// Output: false
 


// Constraints:
// ============
// 2 <= s.length <= 10^5
// s[i] is either '0' or '1'.
// s[0] == '0'
// 1 <= minJump <= maxJump < s.length
 




class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        vector<bool> dp(s.size(), false);
        dp[0] = true;
        for (int i = 1, valid = 0; i < s.size(); ++i) {
            if (i >= minJump && dp[i-minJump])      ++valid;
            if (i > maxJump && dp[i-maxJump-1])     --valid;
            dp[i] = (valid > 0) && (s[i] == '0');
        }
        return dp.back();
    }
};
