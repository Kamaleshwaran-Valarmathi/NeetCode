// Reference: https://leetcode.com/problems/valid-palindrome-ii/



// Given a string s, return true if the s can be palindrome after deleting at most one 
// character from it.

 

// Example 1:
// ==========
// Input: s = "aba"
// Output: true

// Example 2:
// ==========
// Input: s = "abca"
// Output: true
// Explanation: You could delete the character 'c'.

// Example 3:
// ==========
// Input: s = "abc"
// Output: false
 


// Constraints:
// ============
// 1 <= s.length <= 10^5
// s consists of lowercase English letters.
 




class Solution {
public:
    bool isPalindrome(string& str, int left, int right) {
        for ( ; left < right; ++left, --right)
            if (str[left] != str[right])
                return false;
        return true;
    }

    bool validPalindrome(string str) {
        for (int left = 0, right = str.size()-1; left < right; ++left, --right)
            if (str[left] != str[right])
                return isPalindrome(str, left+1, right) || isPalindrome(str, left, right-1);
        return true;
    }
};
