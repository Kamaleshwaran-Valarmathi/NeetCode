// Reference: https://leetcode.com/problems/palindromic-substrings/



// Given a string s, return the number of palindromic substrings in it.
// A string is a palindrome when it reads the same backward as forward.
// A substring is a contiguous sequence of characters within the string.

 

// Example 1:
// ==========
// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".

// Example 2:
// ==========
// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 


// Constraints:
// ============
// 1 <= s.length <= 1000
// s consists of lowercase English letters.





class Solution {
public:
    int helper(string& str, int left, int right) {
        int count = 0;
        while (left >= 0 && right < str.size() && str[left] == str[right]) {
            ++count;
            --left, ++right;
        }
        return count;
    }

    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            count += helper(s, i, i);
            count += helper(s, i, i+1);
        }
        return count;
    }
};
