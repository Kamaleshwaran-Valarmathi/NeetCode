// Reference: https://leetcode.com/problems/multiply-strings/



// Given two non-negative integers num1 and num2 represented as strings, return the product of 
// num1 and num2, also represented as a string.

// Note: You must not use any built-in BigInteger library or convert the inputs to integer 
// directly.

 

// Example 1:
// ==========
// Input: num1 = "2", num2 = "3"
// Output: "6"

// Example 2:
// ==========
// Input: num1 = "123", num2 = "456"
// Output: "56088"
 


// Constraints:
// ============
// 1 <= num1.length, num2.length <= 200
// num1 and num2 consist of digits only.
// Both num1 and num2 do not contain any leading zero, except the number 0 itself.





class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size(), m = num2.size();
        vector<int> digits(n + m, 0);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                int pos1 = i + j, pos2 = i + j + 1;
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + digits[pos2];

                digits[pos1] += (sum / 10);
                digits[pos2] = (sum % 10);
            }
        }

        string prod = "";
        int idx = 0;
        while (idx < digits.size() && digits[idx] == 0)
            ++idx;
        while (idx < digits.size())
            prod += to_string(digits[idx++]);
        return (prod.size() == 0) ? "0" : prod;
    }
};
