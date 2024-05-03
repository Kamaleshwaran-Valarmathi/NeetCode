// Reference: https://leetcode.com/problems/group-anagrams/



// Given an array of strings strs, group the anagrams together. You can return the answer 
// in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or 
// phrase, typically using all the original letters exactly once.

 

// Example 1:
// ==========
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// Example 2:
// ==========
// Input: strs = [""]
// Output: [[""]]

// Example 3:
// ==========
// Input: strs = ["a"]
// Output: [["a"]]
 


// Constraints:
// ============
// 1 <= strs.length <= 10^4
// 0 <= strs[i].length <= 100
// strs[i] consists of lowercase English letters.





class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> groupsIdx;
        vector<vector<string>> res;
        for (int i = 0; i < strs.size(); ++i) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if (groupsIdx.find(temp) != groupsIdx.end()) {
                res[groupsIdx[temp]].push_back(strs[i]);
            } else {
                groupsIdx[temp] = res.size();
                res.push_back({strs[i]});
            }
        }
        return res;
    }
};
