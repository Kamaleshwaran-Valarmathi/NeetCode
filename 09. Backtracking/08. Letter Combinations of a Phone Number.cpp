// Reference: https://leetcode.com/problems/letter-combinations-of-a-phone-number/



// Given a string containing digits from 2-9 inclusive, return all possible letter combinations 
// that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note 
// that 1 does not map to any letters.



// Example 1:
// ==========
// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

// Example 2:
// ==========
// Input: digits = ""
// Output: []

// Example 3:
// ==========
// Input: digits = "2"
// Output: ["a","b","c"]
 


// Constraints:
// ============
// 0 <= digits.length <= 4
// digits[i] is a digit in the range ['2', '9'].





class Solution {
public:
    void combUtils(string &digits, int curIdx, vector<vector<char>> &numCharMap, vector<string> &res, string curComb) {
        if (curIdx == digits.size()) {
            if (digits.size() > 0)
                res.push_back(curComb);
            return;
        }
        for (char ch: numCharMap[digits[curIdx] - '0'])
            combUtils(digits, curIdx + 1, numCharMap, res, curComb + ch);
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        vector<vector<char>> numCharMap = {
            {},
            {},
            {'a', 'b', 'c'},
            {'d', 'e', 'f'},
            {'g', 'h', 'i'},
            {'j', 'k', 'l'},
            {'m', 'n', 'o'},
            {'p', 'q', 'r', 's'},
            {'t', 'u', 'v'},
            {'w', 'x', 'y', 'z'},
        };
        combUtils(digits, 0, numCharMap, res, "");
        return res;
    }
};
