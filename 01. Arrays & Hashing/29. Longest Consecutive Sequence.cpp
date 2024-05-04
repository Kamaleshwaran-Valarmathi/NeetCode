// Reference: https://leetcode.com/problems/longest-consecutive-sequence/



// Given an unsorted array of integers nums, return the length of the longest consecutive 
// elements sequence.

// You must write an algorithm that runs in O(n) time.

 

// Example 1:
// ==========
// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its 
// length is 4.

// Example 2:
// ==========
// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9

 

// Constraints:
// ============
// 0 <= nums.length <= 10^5
// -10^9 <= nums[i] <= 10^9





class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLen = 0;
        unordered_set<int> st(nums.begin(), nums.end());
        for (int i: st) {
            if (st.find(i-1) == st.end()) {
                int curLen = 0;
                for (int itr = i; st.find(itr) != st.end(); ++itr)
                    ++curLen;
                maxLen = max(maxLen, curLen);
            }
        }
        return maxLen;
    }
};
