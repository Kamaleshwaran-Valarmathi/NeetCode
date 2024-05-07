// Reference: https://leetcode.com/problems/minimum-window-substring/



// Given two strings s and t of lengths m and n respectively, return the minimum window 
// substring of s such that every character in t (including duplicates) is included in the 
// window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

 

// Example 1:
// ==========
// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

// Example 2:
// ==========
// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.

// Example 3:
// ==========
// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.
 


// Constraints:
// ============
// m == s.length
// n == t.length
// 1 <= m, n <= 10^5
// s and t consist of uppercase and lowercase English letters.
 


// Follow up: Could you find an algorithm that runs in O(m + n) time?





class Solution {
public:
    bool isValid(unordered_map<char, int>& freq1, unordered_map<char, int>& freq2) {
        for (pair<char, int> itr1: freq1) {
            auto itr2 = freq2.find(itr1.first);
            if (itr2 == freq2.end() || itr2->second < itr1.second)
                return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        unordered_map<char, int> freq1, freq2;
        for (char ch: t)
            ++freq1[ch];
        int start = -1, len = INT_MAX;
        for (int left = 0, right = 0; right < s.size(); ++right) {
            ++freq2[s[right]];
            while (isValid(freq1, freq2)) {
                if (len > (right - left + 1))
                    start = left, len = right - left + 1;
                --freq2[s[left++]];
            }
        }
        return (start == -1) ? "" : s.substr(start, len);
    }
};
