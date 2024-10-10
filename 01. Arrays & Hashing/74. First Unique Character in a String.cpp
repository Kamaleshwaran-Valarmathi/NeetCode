// Reference: https://leetcode.com/problems/first-unique-character-in-a-string/



// Given a string s, find the first non-repeating character in it and return its index. If it does 
//      not exist, return -1.

 

// Example 1:
// ==========
// Input: s = "leetcode"
// Output: 0
// Explanation:
// The character 'l' at index 0 is the first character that does not occur at any other index.

// Example 2:
// ==========
// Input: s = "loveleetcode"
// Output: 2

// Example 3:
// ==========
// Input: s = "aabb"
// Output: -1

 

// Constraints:
// ============
// 1 <= s.length <= 10^5
// s consists of only lowercase English letters.





class Solution {
public:
    int firstUniqChar(string str) {
        vector<pair<int, int>> firstIdx_charFreq(26, {-1, 0}); // {first idx, char freq}
        for (int i = 0; i < str.size(); ++i) {
            if (firstIdx_charFreq[str[i] - 'a'].first == -1)
                firstIdx_charFreq[str[i] - 'a'].first = i;
            firstIdx_charFreq[str[i] - 'a'].second++;
        }
        int minIdx = str.size();
        for (pair<int, int> itr: firstIdx_charFreq)
            if (itr.second == 1)
                minIdx = min(minIdx, itr.first);
        return (minIdx != str.size()) ? minIdx : -1;
    }
};
