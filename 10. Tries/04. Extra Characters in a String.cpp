// Reference: https://leetcode.com/problems/extra-characters-in-a-string/



// You are given a 0-indexed string s and a dictionary of words dictionary. You have to break 
// s into one or more non-overlapping substrings such that each substring is present in 
// dictionary. There may be some extra characters in s which are not present in any of the 
// substrings.

// Return the minimum number of extra characters left over if you break up s optimally.

 

// Example 1:
// ==========
// Input: s = "leetscode", dictionary = ["leet","code","leetcode"]
// Output: 1
// Explanation: We can break s in two substrings: "leet" from index 0 to 3 and "code" from 
//      index 5 to 8. There is only 1 unused character (at index 4), so we return 1.

// Example 2:
// ==========
// Input: s = "sayhelloworld", dictionary = ["hello","world"]
// Output: 3
// Explanation: We can break s in two substrings: "hello" from index 3 to 7 and "world" from 
//      index 8 to 12. The characters at indices 0, 1, 2 are not used in any substring and 
//      thus are considered as extra characters. Hence, we return 3.
 


// Constraints:
// ============
// 1 <= s.length <= 50
// 1 <= dictionary.length <= 50
// 1 <= dictionary[i].length <= 50
// dictionary[i] and s consists of only lowercase English letters
// dictionary contains distinct words
 




class Solution {
public:
    int solve(int stIdx, string& str, unordered_set<string>& dict, vector<int>& dp) {
        if (stIdx == str.size())    return 0;
        if (dp[stIdx] != -1)        return dp[stIdx];
        
        int extraChars = str.size();
        string curStr = "";
        for (int i = stIdx; i < str.size(); ++i) {
            curStr += str[i];
            int curExtraChars = (dict.find(curStr) != dict.end()) ? 0 : curStr.size();
            extraChars = min(extraChars, curExtraChars + solve(i+1, str, dict, dp));
        }
        return dp[stIdx] = extraChars;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int> dp(s.size(), -1);
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        return solve(0, s, dict, dp);
    }
};
