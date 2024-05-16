// Reference: https://leetcode.com/problems/valid-parenthesis-string/



// Given a string s containing only three types of characters: '(', ')' and '*', return true 
// if s is valid.

// The following rules define a valid string:
// - Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// - Any right parenthesis ')' must have a corresponding left parenthesis '('.
// - Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// - '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or 
//      an empty string "".
 


// Example 1:
// ==========
// Input: s = "()"
// Output: true

// Example 2:
// ==========
// Input: s = "(*)"
// Output: true

// Example 3:
// ==========
// Input: s = "(*))"
// Output: true
 


// Constraints:
// ============
// 1 <= s.length <= 100
// s[i] is '(', ')' or '*'.
 




// Approach 1

class Solution {
public:
    bool checkValidString(string str) {
        int low = 0, high = 0;
        for (char ch: str) {
            low += ((ch == '(') ? 1 : -1);
            high += ((ch != ')') ? 1 : -1);
            if (high < 0)
                return false;
            low = max(low, 0);
        }
        return (low == 0);
    }
};





// Approach 2

class Solution {
public:
    bool isValid(int idx, int openCount, string& str, map<pair<int, int>, int>& dp) {
        if (openCount < 0)      return false;
        if (idx == str.size())  return dp[{idx, openCount}] = (openCount == 0);
        if (dp.find({idx, openCount}) != dp.end())  
            return dp[{idx, openCount}];
        bool open = false, close = false, skip = false;
        if (str[idx] == '(' || str[idx] == '*')
            open = isValid(idx+1, openCount+1, str, dp);
        if (str[idx] == ')' || str[idx] == '*')
            close = isValid(idx+1, openCount-1, str, dp);
        if (str[idx] == '*')
            skip = isValid(idx+1, openCount, str, dp);
        return dp[{idx, openCount}] = (open | close | skip);
    }

    bool checkValidString(string s) {
        map<pair<int, int>, int> dp;
        return isValid(0, 0, s, dp);
    }
};
