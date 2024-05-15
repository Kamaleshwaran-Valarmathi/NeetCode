// Reference: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/



// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete as many transactions as you like 
// (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
// - After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the 
// stock before you buy again).

 

// Example 1:
// ==========
// Input: prices = [1,2,3,0,2]
// Output: 3
// Explanation: transactions = [buy, sell, cooldown, buy, sell]

// Example 2:
// ==========
// Input: prices = [1]
// Output: 0

 

// Constraints:
// ============
// 1 <= prices.length <= 5000
// 0 <= prices[i] <= 1000





class Solution {
public:
    int dfs(int idx, int state, vector<int>& prices, vector<vector<int>>& dp) {
        if (idx >= prices.size())   return 0;
        if (dp[idx][state] != -1)   return dp[idx][state];

        if (state == 1) { // buy
            int buy = dfs(idx+1, 0, prices, dp) - prices[idx];
            int cooldown = dfs(idx+1, state, prices, dp);
            dp[idx][state] = max(buy, cooldown);
        } else { // sell
            int sell = dfs(idx+2, 1, prices, dp) + prices[idx];
            int cooldown = dfs(idx+1, state, prices, dp);
            dp[idx][state] = max(sell, cooldown);
        }
        return dp[idx][state];
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return dfs(0, 1, prices, dp);
    }
};
