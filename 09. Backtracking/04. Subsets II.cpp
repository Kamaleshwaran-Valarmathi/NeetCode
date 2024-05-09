// Reference: https://leetcode.com/problems/subsets-ii/



// Given an integer array nums that may contain duplicates, return all possible subsets (the 
// power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:
// ==========
// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

// Example 2:
// ==========
// Input: nums = [0]
// Output: [[],[0]]
 


// Constraints:
// ============
// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10





// Approach 1

class Solution {
public:
    void helper(int stIdx, vector<int>&nums, vector<int>& cur, vector<vector<int>>& res) {
        res.push_back(cur);
        for (int i = stIdx; i < nums.size(); ++i) {
            if (i > stIdx && nums[i] == nums[i-1])
                continue;
            cur.push_back(nums[i]);
            helper(i+1, nums, cur, res);
            cur.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> cur;
        helper(0, nums, cur, res);
        return res;
    }
};





// Approach 2

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < (1 << nums.size()); ++i) {
            vector<int> cur;
            for (int j = 0, bitMask = i; bitMask > 0 ; ++j, bitMask >>= 1)
                if (bitMask & 1)
                    cur.push_back(nums[j]);
            res.insert(cur);
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};
