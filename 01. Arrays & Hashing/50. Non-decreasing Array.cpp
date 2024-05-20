// Reference: https://leetcode.com/problems/non-decreasing-array/



// Given an array nums with n integers, your task is to check if it could become non-decreasing 
// by modifying at most one element.

// We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) 
// such that (0 <= i <= n - 2).

 

// Example 1:
// ==========
// Input: nums = [4,2,3]
// Output: true
// Explanation: You could modify the first 4 to 1 to get a non-decreasing array.

// Example 2:
// ==========
// Input: nums = [4,2,1]
// Output: false
// Explanation: You cannot get a non-decreasing array by modifying at most one element.
 


// Constraints:
// ============
// n == nums.length
// 1 <= n <= 10^4
// -10^5 <= nums[i] <= 10^5
 




class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool seenDecend = false;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i-1] > nums[i]) {
                int prev = (i-2 >= 0) ? nums[i-2] : INT_MIN;
                int next = (i+1 < nums.size()) ? nums[i+1] : INT_MAX;
                if (seenDecend || (prev > nums[i] && nums[i-1] > next))
                    return false;
                seenDecend = true;
            }
        }
        return true;
    }
};
