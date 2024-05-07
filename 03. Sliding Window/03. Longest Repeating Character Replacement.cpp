// Reference: https://leetcode.com/problems/longest-repeating-character-replacement/



// You are given a string s and an integer k. You can choose any character of the string and 
// change it to any other uppercase English character. You can perform this operation at most 
// k times.

// Return the length of the longest substring containing the same letter you can get after 
// performing the above operations.

 

// Example 1:
// ==========
// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.

// Example 2:
// ==========
// Input: s = "AABABBA", k = 1
// Output: 4
// Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.
// There may exists other ways to achieve this answer too.
 


// Constraints:
// ============
// 1 <= s.length <= 10^5
// s consists of only uppercase English letters.
// 0 <= k <= s.length





class Solution {
public:
    int getMaxLen(char ch, string &str, int k) {
        int res = 0, differCount = 0;
        for (int left = 0, right = 0; right < str.size(); ++right) {
            if (str[right] != ch)
                ++differCount;
            while (differCount > k) {
                if (str[left] != ch)
                    --differCount;
                ++left;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }

    int characterReplacement(string str, int k) {
        int res = 0;
        for (char ch = 'A'; ch <= 'Z'; ++ch)
            res = max(res, getMaxLen(ch, str, k));
        return res;
    }
};
