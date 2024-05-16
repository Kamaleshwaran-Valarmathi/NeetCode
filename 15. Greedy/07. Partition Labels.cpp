// Reference: https://leetcode.com/problems/partition-labels/



// You are given a string s. We want to partition the string into as many parts as possible so 
// that each letter appears in at most one part.

// Note that the partition is done so that after concatenating all the parts in order, the 
// resultant string should be s.

// Return a list of integers representing the size of these parts.

 

// Example 1:
// ==========
// Input: s = "ababcbacadefegdehijhklij"
// Output: [9,7,8]
// Explanation:
// The partition is "ababcbaca", "defegde", "hijhklij".
// This is a partition so that each letter appears in at most one part.
// A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.

// Example 2:
// ==========
// Input: s = "eccbbbbdec"
// Output: [10]
 


// Constraints:
// ============
// 1 <= s.length <= 500
// s consists of lowercase English letters.
 




class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res, lastIdx(26, -1);
        for (int i = 0; i < s.size(); ++i)
            lastIdx[s[i] - 'a'] = i;
        int stIdx = 0, endIdx = 0;
        for (int i = 0; i < s.size(); ++i) {
            endIdx = max(endIdx, lastIdx[s[i] - 'a']);
            if (i == endIdx) {
                res.push_back(endIdx - stIdx + 1);
                stIdx = endIdx = i+1;
            }
        }
        return res;
    }
};
