// Reference: https://leetcode.com/problems/subsets/



// Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:
// ==========
// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

// Example 2:
// ==========
// Input: nums = [0]
// Output: [[],[0]]
 


// Constraints:
// ============
// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
// All the numbers of nums are unique.





// Approach 1

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        for (int i = 0; i < (1 << nums.size()); ++i) {
            vector<int> cur;
            for (int j = 0, bitMask = i; bitMask > 0 ; ++j, bitMask >>= 1)
                if (bitMask & 1)
                    cur.push_back(nums[j]);
            res.push_back(cur);
        }
        return res;
    }
};





// Approach 2

class Solution {
public:
    void helper(int start, vector<int>& nums, vector<int>& cur, vector<vector<int>>& res) {
        res.push_back(cur);
        for (int i = start; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            helper(i+1, nums, cur, res);
            cur.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        helper(0, nums, cur, res);
        return res;
    }
};
