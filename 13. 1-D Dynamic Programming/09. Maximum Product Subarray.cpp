// Reference: https://leetcode.com/problems/maximum-product-subarray/



// Given an integer array nums, find a subarray that has the largest product, and return the product.
// The test cases are generated so that the answer will fit in a 32-bit integer.

 

// Example 1:
// ==========
// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.

// Example 2:
// ==========
// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 


// Constraints:
// ============
// 1 <= nums.length <= 2 * 10^4
// -10 <= nums[i] <= 10
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.





class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0], maxProd = nums[0], minProd = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0)
                swap(maxProd, minProd);
            maxProd = max(nums[i], maxProd * nums[i]);
            minProd = min(nums[i], minProd * nums[i]);
            res = max(res, maxProd);
        }
        return res;
    }
};
