// Reference: https://leetcode.com/problems/longest-palindromic-substring/



// Given a string s, return the longest palindromic substring in s.

 

// Example 1:
// ==========
// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

// Example 2:
// ==========
// Input: s = "cbbd"
// Output: "bb"
 


// Constraints:
// ============
// 1 <= s.length <= 1000
// s consist of only digits and English letters.





class Solution {
public:
    int helper(string& str, int left, int right) {
        while (left >= 0 && right < str.size() && str[left] == str[right])
            --left, ++right;
        return right - (left + 1);
    }

    string longestPalindrome(string s) {
        int stIdx = -1, len = 0;
        for (int i = 0; i < s.size(); ++i) {
            int oddLen = helper(s, i, i);
            int evenLen = helper(s, i, i+1);
            int curLen = max(oddLen, evenLen);
            if (curLen > len) {
                stIdx = i - ((curLen - 1) >> 1);
                len = curLen;
            }
        }
        return s.substr(stIdx, len);
    }
};
