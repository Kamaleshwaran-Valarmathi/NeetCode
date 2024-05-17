// Reference: https://leetcode.com/problems/largest-number/



// Given a list of non-negative integers nums, arrange them such that they form the largest 
// number and return it.

// Since the result may be very large, so you need to return a string instead of an integer.

 

// Example 1:
// ==========
// Input: nums = [10,2]
// Output: "210"

// Example 2:
// ==========
// Input: nums = [3,30,34,5,9]
// Output: "9534330"
 


// Constraints:
// ============
// 1 <= nums.length <= 100
// 0 <= nums[i] <= 10^9
 




class Solution {
public:
    static bool comp(int a, int b) {
        string aStr = to_string(a);
        string bStr = to_string(b);
        return (aStr + bStr) > (bStr + aStr);
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);
        string res = "";
        for (int num: nums)
            res += to_string(num);
        return res[0] == '0' ? "0" : res;
    }
};
