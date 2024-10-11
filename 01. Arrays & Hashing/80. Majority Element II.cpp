// Reference: https://leetcode.com/problems/majority-element-ii/



// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

// Example 1:
// ==========
// Input: nums = [3,2,3]
// Output: [3]

// Example 2:
// ==========
// Input: nums = [1]
// Output: [1]

// Example 3:
// ==========
// Input: nums = [1,2]
// Output: [1,2]
 


// Constraints:
// ============
// 1 <= nums.length <= 5 * 10^4
// -10^9 <= nums[i] <= 10^9
 


// Follow up: Could you solve the problem in linear time and in O(1) space?





class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        int candidate1 = 0, candidate2 = 0;
        int threshold = nums.size() / 3;

        for (int i = 0; i < nums.size(); ++i) {
            if (count1 == 0 && nums[i] != candidate2) {
                count1 = 1;
                candidate1 = nums[i];
            } else if (count2 == 0 && nums[i] != candidate1) {
                count2 = 1;
                candidate2 = nums[i];
            } else if (nums[i] == candidate1) {
                ++count1;
            } else if (nums[i] == candidate2) {
                ++count2;
            } else {
                --count1;
                --count2;
            }
        }

        count1 = 0, count2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == candidate1) {
                ++count1;
            } else if (nums[i] == candidate2) {
                ++count2;
            }
        }

        vector<int> res;
        if (count1 > threshold)     res.push_back(candidate1);
        if (count2 > threshold)     res.push_back(candidate2);

        return res;
    }
};
