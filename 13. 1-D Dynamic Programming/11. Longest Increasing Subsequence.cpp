// Reference: https://leetcode.com/problems/longest-increasing-subsequence/



// Given an integer array nums, return the length of the longest strictly increasing subsequence.

 

// Example 1:
// ==========
// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

// Example 2:
// ==========
// Input: nums = [0,1,0,3,2,3]
// Output: 4

// Example 3:
// ==========
// Input: nums = [7,7,7,7,7,7,7]
// Output: 1
 


// Constraints:
// ============
// 1 <= nums.length <= 2500
// -10^4 <= nums[i] <= 10^4
 


// Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?





class Solution {
public:
    int lowerBound(vector<int>& nums, int val) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = (left + right) >> 1;
            (nums[mid] < val) ? (left = mid+1) : (right = mid);
        }
        if (nums.size() > 0 && nums[left] < val)
            ++left;
        return left;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for (int num: nums) {
            // int lbIdx = lower_bound(lis.begin(), lis.end(), num) - lis.begin();
            int lbIdx = lowerBound(lis, num);
            if (lbIdx == lis.size()) {
                lis.push_back(num);
            } else {
                lis[lbIdx] = num;
            }
        }
        return lis.size();
    }
};
