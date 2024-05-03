// Reference: https://leetcode.com/problems/valid-anagram/description/



// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or 
// phrase, typically using all the original letters exactly once.

 

// Example 1:
// ==========
// Input: s = "anagram", t = "nagaram"
// Output: true

// Example 2:
// ==========
// Input: s = "rat", t = "car"
// Output: false
 


// Constraints:
// ============
// 1 <= s.length, t.length <= 5 * 10^4
// s and t consist of lowercase English letters.
 


// Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?





class Solution {
public:
    void populateMap(string &str, unordered_map<char, int> &freq) {
        for (char c: str)
            ++freq[c];
    }

    bool checkSimilarity(string &str, unordered_map<char, int> &freq) {
        for (char c: str) {
            --freq[c];
            if (freq[c] < 0)
                return false;
        }
        return true;
    }

    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        unordered_map<char, int> freq;
        populateMap(s, freq);
        return checkSimilarity(t, freq);
    }
};
