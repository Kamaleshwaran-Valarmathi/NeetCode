// Reference: https://leetcode.com/problems/monotonic-array/



// An array is monotonic if it is either monotone increasing or monotone decreasing.

// An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array 
// nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].

// Given an integer array nums, return true if the given array is monotonic, or false otherwise.

 

// Example 1:
// ==========
// Input: nums = [1,2,2,3]
// Output: true

// Example 2:
// ==========
// Input: nums = [6,5,4,4]
// Output: true

// Example 3:
// ==========
// Input: nums = [1,3,2]
// Output: false
 
 

// Constraints:
// ============
// 1 <= nums.length <= 10^5
// -10^5 <= nums[i] <= 10^5
 




class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool is_dec = false;
        int idx;
        for (idx = 1; idx < nums.size() && nums[idx-1] == nums[idx]; ++idx);
        if (idx >= nums.size())
            return true;
        is_dec = (nums[idx-1] > nums[idx]);
        for (; idx < nums.size(); ++idx) {
            if (is_dec) {
                if (nums[idx-1] < nums[idx])
                    return false;
            } else {
                if (nums[idx-1] > nums[idx])
                    return false;
            }
        }
        return true;
    }
};
