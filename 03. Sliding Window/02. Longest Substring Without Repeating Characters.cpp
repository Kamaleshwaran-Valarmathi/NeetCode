// Reference: https://leetcode.com/problems/longest-substring-without-repeating-characters/



// Given a string s, find the length of the longest 
// substring
//  without repeating characters.

 

// Example 1:
// ==========
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

// Example 2:
// ==========
// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

// Example 3:
// ==========
// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 


// Constraints:
// ============
// 0 <= s.length <= 5 * 10^4
// s consists of English letters, digits, symbols and spaces.





class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int res = 0;
        unordered_set<char> visited;
        for (int left = 0, right = 0; right < str.size(); ++right) {
            while (visited.find(str[right]) != visited.end())
                visited.erase(str[left++]);
            visited.insert(str[right]);
            res = max(res, right - left + 1);
        }
        return res;
    }
};
