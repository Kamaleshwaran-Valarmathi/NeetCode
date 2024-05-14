// Reference: https://leetcode.com/problems/word-break/



// Given a string s and a dictionary of strings wordDict, return true if s can be segmented 
// into a space-separated sequence of one or more dictionary words.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

// Example 1:
// ==========
// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".

// Example 2:
// ==========
// Input: s = "applepenapple", wordDict = ["apple","pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
// Note that you are allowed to reuse a dictionary word.

// Example 3:
// ==========
// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: false
 


// Constraints:
// ============
// 1 <= s.length <= 300
// 1 <= wordDict.length <= 1000
// 1 <= wordDict[i].length <= 20
// s and wordDict[i] consist of only lowercase English letters.
// All the strings of wordDict are unique.





class Solution {
public:
    class Node {
    public:
        bool isCompleteWord = false;
        vector<Node*> child;

        Node() {
            child.resize(26, NULL);
        }
    };

    void insert(Node* trie, string &word) {
        Node* root = trie;
        for (char ch: word) {
            if (root->child[ch - 'a'] == NULL)
                root->child[ch - 'a'] = new Node();
            root = root->child[ch - 'a'];
        }
        root->isCompleteWord = true;
    }

    bool checkValid(string &str, int stIdx, Node* trie, vector<int> &dp) {
        if (stIdx == str.size())    return true;
        if (dp[stIdx] != -1)        return dp[stIdx];
        Node* root = trie;
        for (int curIdx = stIdx; curIdx < str.size(); ++curIdx) {
            if (root->child[str[curIdx] - 'a'] == NULL)
                break;
            root = root->child[str[curIdx] - 'a'];
            if (root->isCompleteWord && checkValid(str, curIdx+1, trie, dp))
                return dp[stIdx] = true;
        }
        return dp[stIdx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        Node* trie = new Node();
        for (string word: wordDict)
            insert(trie, word);
        vector<int> dp(s.size(), -1);
        return checkValid(s, 0, trie, dp);
    }
};
