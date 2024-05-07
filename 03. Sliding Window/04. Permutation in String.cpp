// Reference: https://leetcode.com/problems/permutation-in-string/



// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false 
// otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.

 

// Example 1:
// ==========
// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").

// Example 2:
// ==========
// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false
 


// Constraints:
// ============
// 1 <= s1.length, s2.length <= 10^4
// s1 and s2 consist of lowercase English letters.





class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26, 0), freq2(26, 0);
        for (char ch: s1)
            ++freq1[ch - 'a'];
        for (int i = 0; i < s2.size(); ++i) {
            ++freq2[s2[i] - 'a'];
            if (i >= s1.size())
                --freq2[s2[i - s1.size()] - 'a'];
            if (i >= s1.size()-1 && freq1 == freq2)
                return true;
        }
        return false;
    }
};
