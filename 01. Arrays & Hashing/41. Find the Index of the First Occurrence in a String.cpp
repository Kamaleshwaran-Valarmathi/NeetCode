// Reference: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/



// Given two strings needle and haystack, return the index of the first occurrence of needle in 
// haystack, or -1 if needle is not part of haystack.

 

// Example 1:
// ==========
// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.

// Example 2:
// ==========
// Input: haystack = "leetcode", needle = "leeto"
// Output: -1
// Explanation: "leeto" did not occur in "leetcode", so we return -1.
 


// Constraints:
// ============
// 1 <= haystack.length, needle.length <= 10^4
// haystack and needle consist of only lowercase English characters.
 




class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size())
            return -1;

        long prime = 7, mod = 1e9+7;
        int n = haystack.size(), m = needle.size();

        vector<long> primePowers(n, 1);
        for (int i = 1; i < n; ++i)
            primePowers[i] = (primePowers[i-1] * prime) % mod;
        
        vector<long> haystackHash(n+1, 0);
        for (int i = 0; i < n; ++i)
            haystackHash[i+1] = (haystackHash[i] + (haystack[i] - 'a' + 1) * primePowers[i]) % mod;
        
        long needleHash = 0;
        for (int i = 0; i < m; ++i)
            needleHash = (needleHash + (needle[i] - 'a' + 1) * primePowers[i]) % mod;
        
        for (int i = 0; i <= (n-m); ++i) {
            long curHash = (haystackHash[i+m] - haystackHash[i] + mod) % mod;
            if (curHash == (needleHash * primePowers[i]) % mod)
                return i;
        }
        return -1;
    }
};
