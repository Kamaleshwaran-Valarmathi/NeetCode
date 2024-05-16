// Reference: https://leetcode.com/problems/burst-balloons/



// You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on 
// it represented by an array nums. You are asked to burst all the balloons.

// If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If 
// i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with 
// a 1 painted on it.

// Return the maximum coins you can collect by bursting the balloons wisely.

 

// Example 1:
// ==========
// Input: nums = [3,1,5,8]
// Output: 167
// Explanation:
// nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
// coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167

// Example 2:
// ==========
// Input: nums = [1,5]
// Output: 10
 


// Constraints:
// ============
// n == nums.length
// 1 <= n <= 300
// 0 <= nums[i] <= 100





class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 0; len < n; ++len) {
            for (int i = 0, j = len; j < n; ++i, ++j) {
                for (int k = i; k <= j; ++k) {
                    int left = (k == i) ? 0 : dp[i][k-1];
                    int right = (k == j) ? 0 : dp[k+1][j];
                    int mid = (i == 0 ? 1 : nums[i-1]) * nums[k] * (j == n-1 ? 1 : nums[j+1]);
                    dp[i][j] = max(dp[i][j], left + mid + right);
                }
            }
        }
        return dp[0][n-1];
    }
};
