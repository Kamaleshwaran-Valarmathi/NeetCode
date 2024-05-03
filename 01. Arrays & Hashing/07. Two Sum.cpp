// Reference: https://leetcode.com/problems/two-sum/



// Given an array of integers nums and an integer target, return indices of the two numbers 
// such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the 
// same element twice.

// You can return the answer in any order.

 

// Example 1:
// ==========
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

// Example 2:
// ==========
// Input: nums = [3,2,4], target = 6
// Output: [1,2]

// Example 3:
// ==========
// Input: nums = [3,3], target = 6
// Output: [0,1]
 


// Constraints:
// ============
// 2 <= nums.length <= 10^4
// -10^9 <= nums[i] <= 10^9
// -10^9 <= target <= 10^9
// Only one valid answer exists.
 


// Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?





// Approach 1
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numIdx;
        for (int i = 0; i < nums.size(); ++i) {
            int rem = target - nums[i];
            if (numIdx.find(rem) != numIdx.end())
                return {i, numIdx[rem]};
            numIdx[nums[i]] = i;
        }
        return {};
    }
};



// Approach 2
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> nums_idx;
        for (int i = 0; i < nums.size(); ++i)
            nums_idx.push_back({nums[i], i});
        sort(nums_idx.begin(), nums_idx.end());
        for (int i = 0, j = nums_idx.size()-1; i < j; ) {
            int cur = nums_idx[i].first + nums_idx[j].first;
            if (cur == target) {
                return {nums_idx[i].second, nums_idx[j].second};
            }
            (cur < target) ? ++i : --j;
        }
        return {};
    }
};
