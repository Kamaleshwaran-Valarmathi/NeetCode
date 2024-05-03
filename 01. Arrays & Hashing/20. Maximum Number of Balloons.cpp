// Reference: https://leetcode.com/problems/maximum-number-of-balloons/



// Given a string text, you want to use the characters of text to form as many instances of 
// the word "balloon" as possible.

// You can use each character in text at most once. Return the maximum number of instances 
// that can be formed.

 

// Example 1:
// ==========
// Input: text = "nlaebolko"
// Output: 1

// Example 2:
// ==========
// Input: text = "loonbalxballpoon"
// Output: 2

// Example 3:
// ==========
// Input: text = "leetcode"
// Output: 0
 


// Constraints:
// ============
// 1 <= text.length <= 10^4
// text consists of lower case English letters only.





class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26, 0);
        for (char c: text)
            ++freq[c - 'a'];
        
        vector<pair<char, int>> word = {{'b', 1}, {'a', 1}, {'l', 2}, {'o', 2}, {'n', 1}};
        int maxCount = INT_MAX;
        for (pair<char, int> itr: word)
            maxCount = min(maxCount, freq[itr.first - 'a'] / itr.second);
        return maxCount;
    }
};
