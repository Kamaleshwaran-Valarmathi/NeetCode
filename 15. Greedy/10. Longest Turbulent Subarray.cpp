// Reference: https://leetcode.com/problems/longest-turbulent-subarray/



// Given an integer array arr, return the length of a maximum size turbulent subarray of arr.

// A subarray is turbulent if the comparison sign flips between each adjacent pair of elements 
// in the subarray.

// More formally, a subarray [arr[i], arr[i + 1], ..., arr[j]] of arr is said to be turbulent 
// if and only if:
// - For i <= k < j:
//    - arr[k] > arr[k + 1] when k is odd, and
//    - arr[k] < arr[k + 1] when k is even.
// - Or, for i <= k < j:
//    - arr[k] > arr[k + 1] when k is even, and
//    - arr[k] < arr[k + 1] when k is odd.
 


// Example 1:
// ==========
// Input: arr = [9,4,2,10,7,8,8,1,9]
// Output: 5
// Explanation: arr[1] > arr[2] < arr[3] > arr[4] < arr[5]

// Example 2:
// ==========
// Input: arr = [4,8,12,16]
// Output: 2

// Example 3:
// ==========
// Input: arr = [100]
// Output: 1
 


// Constraints:
// ============
// 1 <= arr.length <= 4 * 10^4
// 0 <= arr[i] <= 10^9
 




class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if (arr.size() <= 1)
            return arr.size();
        
        int maxLen = 1, curLen = 1;
        bool shouldInc = arr[0] < arr[1];
        for (int i = 1; i < arr.size(); ++i) {
            if ((shouldInc && arr[i-1] < arr[i]) || (!shouldInc && arr[i-1] > arr[i])) {
                ++curLen;
                shouldInc ^= true;
            } else {
                curLen = (arr[i-1] == arr[i]) ? 1 : 2;
                shouldInc = !(arr[i-1] < arr[i]);
            }
            maxLen = max(maxLen, curLen);
        }
        return maxLen;
    }
};
