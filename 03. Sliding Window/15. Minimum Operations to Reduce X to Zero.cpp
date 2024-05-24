// Reference: https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/



// You are given an integer array nums and an integer x. In one operation, you can either remove 
// the leftmost or the rightmost element from the array nums and subtract its value from x. Note 
// that this modifies the array for future operations.

// Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, 
// return -1.

 

// Example 1:
// ==========
// Input: nums = [1,1,4,2,3], x = 5
// Output: 2
// Explanation: The optimal solution is to remove the last two elements to reduce x to zero.

// Example 2:
// ==========
// Input: nums = [5,6,7,8,9], x = 4
// Output: -1

// Example 3:
// ==========
// Input: nums = [3,2,20,1,1,3], x = 10
// Output: 5
// Explanation: The optimal solution is to remove the last three elements and the first two 
//      elements (5 operations in total) to reduce x to zero.
 


// Constraints:
// ============
// 1 <= nums.length <= 10^5
// 1 <= nums[i] <= 10^4
// 1 <= x <= 10^9
 




// Approach 1

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), res = INT_MAX, sum = 0;
        for (int left = 0, right = 0; right < (n << 1); ++right) {
            sum += nums[right % n];
            while (sum >= x) {
                if (sum == x && (right - left + 1) <= n && (left == 0 || right == (n << 1) - 1 || (left < n && right > n)))
                    res = min(res, right - left + 1);
                sum -= nums[left % n];
                ++left;
            }
        }
        return (res == INT_MAX) ? -1 : res;
    }
};





// Approach 2

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        vector<int> prefixSum(nums.size());
        prefixSum[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i)
            prefixSum[i] = prefixSum[i-1] + nums[i];
        
        int res = INT_MAX, sum = 0;
        int idx = (upper_bound(prefixSum.begin(), prefixSum.end(), x) - prefixSum.begin()) - 1;
        if (idx >= 0 && prefixSum[idx] == x)
            res = idx + 1;
        
        for (int i = nums.size()-1; i >= 0 && sum + nums[i] <= x; --i) {
            sum += nums[i];
            int idx = (upper_bound(prefixSum.begin(), prefixSum.end(), (x - sum)) - prefixSum.begin()) - 1;
            if (idx < 0 && sum == x) {
                res = min(res, int(nums.size() - i));
            } else if (idx >= 0 && idx < i && prefixSum[idx] == (x - sum)) {
                res = min(res, (idx + 1) + int(nums.size() - i));
            }
        }

        return (res == INT_MAX) ? -1 : res;
    }
};
