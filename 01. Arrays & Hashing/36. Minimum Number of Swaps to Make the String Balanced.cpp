// Reference: https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/



// You are given a 0-indexed string s of even length n. The string consists of exactly n / 2 
// opening brackets '[' and n / 2 closing brackets ']'.

// A string is called balanced if and only if:

// It is the empty string, or
// It can be written as AB, where both A and B are balanced strings, or
// It can be written as [C], where C is a balanced string.
// You may swap the brackets at any two indices any number of times.

// Return the minimum number of swaps to make s balanced.

 

// Example 1:
// ==========
// Input: s = "][]["
// Output: 1
// Explanation: You can make the string balanced by swapping index 0 with index 3.
// The resulting string is "[[]]".

// Example 2:
// ==========
// Input: s = "]]][[["
// Output: 2
// Explanation: You can do the following to make the string balanced:
// - Swap index 0 with index 4. s = "[]][][".
// - Swap index 1 with index 5. s = "[[][]]".
// The resulting string is "[[][]]".

// Example 3:
// ==========
// Input: s = "[]"
// Output: 0
// Explanation: The string is already balanced.
 


// Constraints:
// ============
// n == s.length
// 2 <= n <= 10^6
// n is even.
// s[i] is either '[' or ']'.
// The number of opening brackets '[' equals n / 2, and the number of closing brackets ']' equals n / 2.





// Approach 1
class Solution {
public:
    stack<char> leftSt, rightSt;

    int findInvalidFromLeft(string &str, int leftIdx) {
        for (int i = leftIdx; i < str.size(); ++i) {
            if (str[i] == '[') {
                leftSt.push(str[i]);
            } else {
                if (leftSt.empty())
                    return i;
                leftSt.pop();
            }
        }
        return -1;
    }

    int findInvalidFromRight(string &str, int rightIdx) {
        for (int i = rightIdx; i >= 0; --i) {
            if (str[i] == ']') {
                rightSt.push(str[i]);
            } else {
                if (rightSt.empty())
                    return i;
                rightSt.pop();
            }
        }
        return -1;
    }

    int minSwaps(string s) {
        int res = 0;
        for (int leftIdx = 0, rightIdx = s.size()-1; leftIdx < rightIdx; ++res) {
            leftIdx = findInvalidFromLeft(s, leftIdx);
            rightIdx = findInvalidFromRight(s, rightIdx);
            if (leftIdx != -1 && rightIdx != -1) {
                swap(s[leftIdx], s[rightIdx]);
            } else {
                break;
            }
        }
        return res;
    }
};





// Approach 2
class Solution {
public:
    int minSwaps(string s) {
        int res = 0, openCount = 0, closeCount = 0;
        for (char ch: s) {
            (ch == '[') ? ++openCount : ++closeCount;
            if (openCount < closeCount)
                ++res, ++openCount, --closeCount;
        }
        return res;
    }
};
