// Reference: https://leetcode.com/problems/sort-an-array/



// Given an array of integers nums, sort the array in ascending order and return it.

// You must solve the problem without using any built-in functions in O(nlog(n)) time 
// complexity and with the smallest space complexity possible.

 

// Example 1:
// ==========
// Input: nums = [5,2,3,1]
// Output: [1,2,3,5]
// Explanation: After sorting the array, the positions of some numbers are not changed (for 
// example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).

// Example 2:
// ==========
// Input: nums = [5,1,1,2,0,0]
// Output: [0,0,1,1,2,5]
// Explanation: Note that the values of nums are not necessairly unique.
 


// Constraints:
// ============
// 1 <= nums.length <= 5 * 10^4
// -5 * 10^4 <= nums[i] <= 5 * 10^4





class Solution {
public:
    void heapify(vector<int> &nums, int idx, int n) {
        int largestIdx = idx;
        int left = (idx << 1) + 1;
        int right = (idx << 1) + 2;
        largestIdx = (left < n && nums[idx] < nums[left]) ? left : idx;
        largestIdx = (right < n && nums[largestIdx] < nums[right]) ? right : largestIdx;
        if (largestIdx ^ idx) {
            swap(nums[largestIdx], nums[idx]);
            heapify(nums, largestIdx, n);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        for (int i = nums.size() >> 1; i >= 0; --i)
            heapify(nums, i, nums.size());
        for (int i = nums.size()-1; i >= 0; --i) {
            swap(nums[0], nums[i]);
            heapify(nums, 0, i);
        }
        return nums;
    }
};
