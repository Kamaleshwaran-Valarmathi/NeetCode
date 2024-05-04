// Reference: https://leetcode.com/problems/subarray-sum-equals-k/



// Given an array of integers nums and an integer k, return the total number of subarrays 
// whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

 

// Example 1:
// ==========
// Input: nums = [1,1,1], k = 2
// Output: 2

// Example 2:
// ==========
// Input: nums = [1,2,3], k = 3
// Output: 2
 


// Constraints:
// ============
// 1 <= nums.length <= 2 * 10^4
// -1000 <= nums[i] <= 1000
// -10^7 <= k <= 10^7





class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefSumFreq = {{0, 1}};
        int count = 0, prefSum = 0;
        for (int i: nums) {
            prefSum += i;
            count += prefSumFreq[prefSum - k];
            ++prefSumFreq[prefSum];
        }
        return count;
    }
};
