// Reference: https://leetcode.com/problems/word-ladder/



// A transformation sequence from word beginWord to word endWord using a dictionary wordList 
// is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// - Every adjacent pair of words differs by a single letter.
// - Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// - sk == endWord

// Given two words, beginWord and endWord, and a dictionary wordList, return the number of 
// words in the shortest transformation sequence from beginWord to endWord, or 0 if no such 
// sequence exists.

 

// Example 1:
// ==========
// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: 5
// Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", 
//      which is 5 words long.

// Example 2:
// ==========
// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
// Output: 0
// Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation 
//      sequence.
 


// Constraints:
// ============
// 1 <= beginWord.length <= 10
// endWord.length == beginWord.length
// 1 <= wordList.length <= 5000
// wordList[i].length == beginWord.length
// beginWord, endWord, and wordList[i] consist of lowercase English letters.
// beginWord != endWord
// All the words in wordList are unique





class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (words.find(endWord) == words.end())
            return 0;
        
        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);
        
        int dist = 1;
        while (!q.empty()) {
            for (int i = 0, sz = q.size(); i < sz; ++i) {
                string curWord = q.front();
                q.pop();
                if (curWord == endWord)
                    return dist;
                for (int j = 0; j < curWord.size(); ++j) {
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        string nextWord = curWord;
                        nextWord[j] = ch;
                        if (words.find(nextWord) != words.end() && visited.find(nextWord) == visited.end()) {
                            q.push(nextWord);
                            visited.insert(nextWord);
                        }
                    }
                }
            }
            ++dist;
        }
        return 0;
    }
};
