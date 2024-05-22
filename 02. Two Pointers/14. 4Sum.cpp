// Reference: https://leetcode.com/problems/4sum/



// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], 
// nums[b], nums[c], nums[d]] such that:
// - 0 <= a, b, c, d < n
// - a, b, c, and d are distinct.
// - nums[a] + nums[b] + nums[c] + nums[d] == target

// You may return the answer in any order.

 

// Example 1:
// ==========
// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

// Example 2:
// ==========
// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]
 


// Constraints:
// ============
// 1 <= nums.length <= 200
// -10^9 <= nums[i] <= 10^9
// -10^9 <= target <= 10^9
 




class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i+1; j < nums.size(); ++j) {
                int k = j+1, l = nums.size()-1;
                while (k < l) {
                    long curSum = 0l + nums[i] + nums[j] + nums[k] + nums[l];
                    if (curSum == target) {
                        res.insert({nums[i], nums[j], nums[k], nums[l]});
                        ++k, --l;
                    } else {
                        (curSum < target) ? ++k : --l;
                    }
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};
