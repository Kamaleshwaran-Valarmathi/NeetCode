// Reference: https://leetcode.com/problems/combination-sum-ii/



// Given a collection of candidate numbers (candidates) and a target number (target), find all 
// unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

 

// Example 1:
// ==========
// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]

// Example 2:
// ==========
// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]
 


// Constraints:
// ============
// 1 <= candidates.length <= 100
// 1 <= candidates[i] <= 50
// 1 <= target <= 30





class Solution {
public:
    void helper(int stIdx, vector<int>& nums, int target, int curSum, vector<int>& cur, vector<vector<int>>& res) {
        if (stIdx > nums.size() || curSum > target)
            return;
        if (curSum == target) {
            res.push_back(cur);
            return;
        }
        for (int i = stIdx; i < nums.size(); ++i) {
            if (i > stIdx && nums[i] == nums[i-1])
                continue;
            cur.push_back(nums[i]);
            helper(i+1, nums, target, curSum+nums[i], cur, res);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        helper(0, candidates, target, 0, cur, res);
        return res;
    }
};
