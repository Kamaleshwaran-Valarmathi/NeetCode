// Reference: https://leetcode.com/problems/maximum-subarray/



// Given an integer array nums, find the subarray with the largest sum, and return its sum.

 

// Example 1:
// ==========
// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.

// Example 2:
// ==========
// Input: nums = [1]
// Output: 1
// Explanation: The subarray [1] has the largest sum 1.

// Example 3:
// ==========
// Input: nums = [5,4,-1,7,8]
// Output: 23
// Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 


// Constraints:
// ============
// 1 <= nums.length <= 10^5
// -10^4 <= nums[i] <= 10^4
 


// Follow up: If you have figured out the O(n) solution, try coding another solution using the 
// divide and conquer approach, which is more subtle.





// Approach 1

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, curSum = 0;
        for (int num: nums) {
            curSum += num;
            maxSum = max(maxSum, curSum);
            curSum = max(0, curSum);
        }
        return maxSum;
    }
};





// Approach 2

class Solution {
public:
    int helper(int left, int right, vector<int>& nums) {
        if (left > right)
            return INT_MIN;
        int mid = (left + right) >> 1;
        int leftSum = 0, rightSum = 0;
        for (int i = mid-1, curSum = 0; i >= left; --i) {
            curSum += nums[i];
            leftSum = max(leftSum, curSum);
        }
        for (int i = mid+1, curSum = 0; i <= right; ++i) {
            curSum += nums[i];
            rightSum = max(rightSum, curSum);
        }
        return max({helper(left, mid-1, nums), helper(mid+1, right, nums), leftSum + nums[mid] + rightSum});
    }

    int maxSubArray(vector<int>& nums) {
        return helper(0, nums.size()-1, nums);
    }
};
