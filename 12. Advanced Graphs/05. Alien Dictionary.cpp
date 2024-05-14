// Reference: https://leetcode.ca/2016-08-25-269-Alien-Dictionary/



// There is a new alien language which uses the latin alphabet. However, the order among 
// letters are unknown to you. You receive a list of non-empty words from the dictionary, 
// where words are sorted lexicographically by the rules of this new language. Derive the 
// order of letters in this language.



// Example 1:
// ==========
// Input:
// [
//   "wrt",
//   "wrf",
//   "er",
//   "ett",
//   "rftt"
// ]
// Output: "wertf"

// Example 2:
// ==========
// Input:
// [
//   "z",
//   "x"
// ]
// Output: "zx"

// Example 3:
// ==========
// Input:
// [
//   "z",
//   "x",
//   "z"
// ]
// Output: "" 
// Explanation: The order is invalid, so return "".



// Constraints:
// ============
// 1 <= words.length <= 100
// 1 <= words[i].length <= 100
// words[i] consists of only lowercase English letters.



// Note:
// - You may assume all letters are in lowercase.
// - You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
// - If the order is invalid, return an empty string.
// - There may be multiple valid order of letters, return any one of them is fine.





class Solution {
public:
    string alienOrder(vector<string>& A) {
        // Graph Construction
        unordered_map<char, unordered_set<char>> adjLs;
        for (string word: A)
            for (char ch: word)
                adjLs[ch] = {};
        
        for (int i = 0; i+1 < A.size(); ++i) {
            for (int j = 0; j < A.size(); ++j) {
                if (A[i][j] != A[i+1][j]) {
                    adjLs[A[i][j]].insert(A[i+1][j]);
                    break;
                }
            }
        }

        // Topological Sort
        vector<int> indegree(26, 0);
        for (auto [key, value]: adjLs)
            for (char ch: value)
                ++indegree[ch - 'a'];
        
        queue<char> q;
        for (char ch = 'a'; ch <= 'z'; ++ch)
            if (indegree[ch - 'a'] == 0 && adjLs.find(ch) != adjLs.end())
                q.push(ch);
        
        string res = "";
        while (!q.empty()) {
            int curChar = q.front();
            q.pop();
            res += curChar;
            for (char ch: adjLs[curChar]) {
                --indegree[ch - 'a'];
                if (indegree[ch - 'a'] == 0)
                    q.push(ch);
            }
        }

        return (res.size() == adjLs.size()) ? res : "";
    }
};
