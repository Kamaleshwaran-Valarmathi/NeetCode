// Reference: https://leetcode.com/problems/find-k-closest-elements/



// Given a sorted integer array arr, two integers k and x, return the k closest integers to x 
// in the array. The result should also be sorted in ascending order.

// An integer a is closer to x than an integer b if:
// - |a - x| < |b - x|, or
// - |a - x| == |b - x| and a < b
 


// Example 1:
// ==========
// Input: arr = [1,2,3,4,5], k = 4, x = 3
// Output: [1,2,3,4]

// Example 2:
// ==========
// Input: arr = [1,2,3,4,5], k = 4, x = -1
// Output: [1,2,3,4]
 


// Constraints:
// ============
// 1 <= k <= arr.length
// 1 <= arr.length <= 1^04
// arr is sorted in ascending order.
// -10^4 <= arr[i], x <= 10^4
 




class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int lbIdx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        if ((lbIdx == arr.size()) || (lbIdx > 0 && abs(arr[lbIdx-1] - x) <= abs(arr[lbIdx] - x)))
            --lbIdx;

        int left = lbIdx, right = lbIdx;
        while (--k && (left > 0 || right < arr.size()-1)) {
            if (left > 0 && right < arr.size()-1) {
                (abs(arr[left-1] - x) <= abs(arr[right+1] - x)) ? --left : ++right;
            } else {
                (left > 0) ? --left : ++right;
            }
        }

        return vector<int>(arr.begin()+left, arr.begin()+(right+1));
    }
};
