// Reference: https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/



// You are given a binary string s. You are allowed to perform two types of operations on the 
// string in any sequence:
// - Type-1: Remove the character at the start of the string s and append it to the end of the string.
// - Type-2: Pick any character in s and flip its value, i.e., if its value is '0' it becomes 
//      '1' and vice-versa.

// Return the minimum number of type-2 operations you need to perform such that s becomes alternating.
// The string is called alternating if no two adjacent characters are equal.
// For example, the strings "010" and "1010" are alternating, while the string "0100" is not.



// Example 1:
// ==========
// Input: s = "111000"
// Output: 2
// Explanation: Use the first operation two times to make s = "100011".
// Then, use the second operation on the third and sixth elements to make s = "101010".

// Example 2:
// ==========
// Input: s = "010"
// Output: 0
// Explanation: The string is already alternating.

// Example 3:
// ==========
// Input: s = "1110"
// Output: 1
// Explanation: Use the second operation on the second element to make s = "1010".
 


// Constraints:
// ============
// 1 <= s.length <= 10^5
// s[i] is either '0' or '1'
 




class Solution {
public:
    int minFlips(string s) {
        int n = s.size(), diff1 = 0, diff2 = 0, res = s.size();
        string str1 = "", str2 = "";
        for (int i = 0; i < (n << 1); ++i) {
            str1 += ((i & 1) ? '1' : '0');
            str2 += ((i & 1) ? '0' : '1');
        }
        
        s = s + s;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != str1[i])    ++diff1;
            if (s[i] != str2[i])    ++diff2;
            if (i >= n) {
                if (s[i-n] != str1[i-n])    --diff1;
                if (s[i-n] != str2[i-n])    --diff2;
            }
            if (i >= n-1)
                res = min({res, diff1, diff2});
        }

        return res;
    }
};
