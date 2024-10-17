// Reference: https://leetcode.com/problems/sequential-digits/



// An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

// Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

 

// Example 1:
// ==========
// Input: low = 100, high = 300
// Output: [123,234]

// Example 2:
// ==========
// Input: low = 1000, high = 13000
// Output: [1234,2345,3456,4567,5678,6789,12345]
 


// Constraints:
// ============
// 10 <= low <= high <= 10^9





// Approach 1
// ==========
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        queue<int> nums({1, 2, 3, 4, 5, 6, 7, 8, 9});
        while (!nums.empty()) {
            int curNum = nums.front();
            nums.pop();
            int lastDigit = curNum % 10;
            if (lastDigit < 9)
                nums.push((curNum * 10) + (lastDigit + 1));
            if ((low <= curNum) && (high >= curNum))
                res.push_back(curNum);
        }
        return res;
    }
};



// Approach 2
// ==========
class Solution {
    bool generateNum(int &num, int firstDigit, int digitCount) {
        int curDigit = firstDigit;
        while (curDigit < 10 && digitCount--) {
            num = (num * 10) + curDigit;
            ++curDigit;
        }
        return (digitCount < 0);
    }

public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        int digitCount = to_string(low).size();
        int firstDigit = to_string(low)[0] - '0';
        while (digitCount < 10) {
            int num = 0;
            if (generateNum(num, firstDigit, digitCount)) {
                if (high < num)
                    break;
                ++firstDigit;
            } else {
                firstDigit = 1;
                ++digitCount;
            }

            if (low <= num && high >= num)
                res.push_back(num);
        }
        return res;
    }
};
