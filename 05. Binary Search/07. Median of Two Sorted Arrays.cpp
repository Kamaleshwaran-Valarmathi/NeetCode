// Reference: https://leetcode.com/problems/median-of-two-sorted-arrays/



// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of 
// the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

 

// Example 1:
// ==========
// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.

// Example 2:
// ==========
// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 


// Constraints:
// ============
// nums1.length == m
// nums2.length == n
// 0 <= m <= 1000
// 0 <= n <= 1000
// 1 <= m + n <= 2000
// -10^6 <= nums1[i], nums2[i] <= 10^6





class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        if (n1 == 0)
            return (n2 & 1) ? nums2[n2 >> 1] : ((nums2[n2 >> 1] + nums2[(n2 >> 1) - 1]) / 2.0);
        int left = 0, right = n1, half = (n1 + n2 + 1) >> 1;
        while (left <= right) {
            int mid1 = (left + right) >> 1;
            int mid2 = half - mid1;
            double l1 = (mid1 > 0) ? nums1[mid1-1] : INT_MIN;
            double l2 = (mid2 > 0) ? nums2[mid2-1] : INT_MIN;
            double r1 = (mid1 < n1) ? nums1[mid1] : INT_MAX;
            double r2 = (mid2 < n2) ? nums2[mid2] : INT_MAX;
            if (l1 <= r2 && l2 <= r1)
                return ((n1 + n2) & 1) ? (max(l1, l2)) : ((max(l1, l2) + min(r1, r2)) / 2.0);
            (l1 > r2) ? (right = mid1-1) : (left = mid1+1);
        }
        return -1;
    }
};
