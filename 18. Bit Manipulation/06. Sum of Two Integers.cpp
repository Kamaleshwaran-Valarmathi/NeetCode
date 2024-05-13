// Reference: https://leetcode.com/problems/sum-of-two-integers/



// Given two integers a and b, return the sum of the two integers without using the operators 
// + and -.

 

// Example 1:
// ==========
// Input: a = 1, b = 2
// Output: 3

// Example 2:
// ==========
// Input: a = 2, b = 3
// Output: 5
 


// Constraints:
// ============
// -1000 <= a, b <= 1000





// Approach 1

class Solution {
public:
    int getSum(int a, int b) {
        for (int sum = 0, carry = 0; b; a = sum, b = carry) {
            sum = (a ^ b);
            carry = (a & b) << 1;
        }
        return a;
    }
};





// Approach 2

class Solution {
public:
    int getSum(int a, int b) {
        return (b == 0) ? a : getSum(a ^ b, (a & b) << 1);
    }
};
