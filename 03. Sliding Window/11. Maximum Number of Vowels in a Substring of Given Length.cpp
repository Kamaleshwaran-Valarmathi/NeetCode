// Reference: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/



// Given a string s and an integer k, return the maximum number of vowel letters in any 
// substring of s with length k.

// Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

 

// Example 1:
// ==========
// Input: s = "abciiidef", k = 3
// Output: 3
// Explanation: The substring "iii" contains 3 vowel letters.

// Example 2:
// ==========
// Input: s = "aeiou", k = 2
// Output: 2
// Explanation: Any substring of length 2 contains 2 vowels.

// Example 3:
// ==========
// Input: s = "leetcode", k = 3
// Output: 2
// Explanation: "lee", "eet" and "ode" contain 2 vowels.
 


// Constraints:
// ============
// 1 <= s.length <= 10^5
// s consists of lowercase English letters.
// 1 <= k <= s.length
 




class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    int maxVowels(string s, int k) {
        int maxVowelCount = 0, curVowelCount = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (isVowel(s[i]))
                ++curVowelCount;
            if (i >= k && isVowel(s[i-k]))
                --curVowelCount;
            if (i >= k-1)
                maxVowelCount = max(maxVowelCount, curVowelCount);
        }
        return maxVowelCount;
    }
};
