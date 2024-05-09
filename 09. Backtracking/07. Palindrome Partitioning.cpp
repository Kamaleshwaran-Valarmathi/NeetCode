// Reference: https://leetcode.com/problems/palindrome-partitioning/



// Given a string s, partition s such that every substring of the partition is a palindrome. 
// Return all possible palindrome partitioning of s.

 

// Example 1:
// ==========
// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]

// Example 2:
// ==========
// Input: s = "a"
// Output: [["a"]]
 


// Constraints:
// ============
// 1 <= s.length <= 16
// s contains only lowercase English letters.





class Solution {
public:
    bool isPalindrome(int st, int ed, string& str) {
        while (st < ed) {
            if (str[st] != str[ed])
                return false;
            ++st, --ed;
        }
        return true;
    }

    void helper(int stIdx, string& str, vector<string>& cur, vector<vector<string>>& res) {
        if (stIdx == str.size()) {
            res.push_back(cur);
            return;
        }
        for (int i = stIdx; i < str.size(); ++i) {
            if (isPalindrome(stIdx, i, str)) {
                cur.push_back(str.substr(stIdx, i - stIdx + 1));
                helper(i+1, str, cur, res);
                cur.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> cur;
        helper(0, s, cur, res);
        return res;
    }
};
