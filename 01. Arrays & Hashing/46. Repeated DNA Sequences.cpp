// Reference: https://leetcode.com/problems/repeated-dna-sequences/



// The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.
// - For example, "ACGAATTCCG" is a DNA sequence.

// When studying DNA, it is useful to identify repeated sequences within the DNA.

// Given a string s that represents a DNA sequence, return all the 10-letter-long sequences 
// (substrings) that occur more than once in a DNA molecule. You may return the answer in any 
// order.

 

// Example 1:
// ==========
// Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
// Output: ["AAAAACCCCC","CCCCCAAAAA"]

// Example 2:
// ==========
// Input: s = "AAAAAAAAAAAAA"
// Output: ["AAAAAAAAAA"]
 


// Constraints:
// ============
// 1 <= s.length <= 10^5
// s[i] is either 'A', 'C', 'G', or 'T'
 




class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> freqMap;
        string cur = "";
        for (int i = 9; i < s.size(); ++i)
            freqMap[s.substr(i-9, 10)]++;

        vector<string> res;
        for (auto [subStr, freq]: freqMap)
            if (freq > 1)
                res.push_back(subStr);
        return res;
    }
};
