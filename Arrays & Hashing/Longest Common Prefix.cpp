// Reference: https://leetcode.com/problems/longest-common-prefix/



// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

 

// Example 1:
// ==========
// Input: strs = ["flower","flow","flight"]
// Output: "fl"

// Example 2:
// ==========
// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
 


// Constraints:
// ============
// 1 <= strs.length <= 200
// 0 <= strs[i].length <= 200
// strs[i] consists of only lowercase English letters.





class Solution {
public:
    bool isValid(int idx, vector<string> &strs) {
        for (string str: strs)
            if (idx >= str.size() || str[idx] != strs[0][idx])
                return false;
        return true;
    }

    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        for (int i = 0; isValid(i, strs); ++i)
            res += strs[0][i];
        return res;
    }
};
