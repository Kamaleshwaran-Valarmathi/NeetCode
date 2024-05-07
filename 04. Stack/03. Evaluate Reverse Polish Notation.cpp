// Reference: https://leetcode.com/problems/evaluate-reverse-polish-notation/



// You are given an array of strings tokens that represents an arithmetic expression in a 
// Reverse Polish Notation.

// Evaluate the expression. Return an integer that represents the value of the expression.

// Note that:
// - The valid operators are '+', '-', '*', and '/'.
// - Each operand may be an integer or another expression.
// - The division between two integers always truncates toward zero.
// - There will not be any division by zero.
// - The input represents a valid arithmetic expression in a reverse polish notation.
// - The answer and all the intermediate calculations can be represented in a 32-bit integer.
 


// Example 1:
// ==========
// Input: tokens = ["2","1","+","3","*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9

// Example 2:
// ==========
// Input: tokens = ["4","13","5","/","+"]
// Output: 6
// Explanation: (4 + (13 / 5)) = 6

// Example 3:
// ==========
// Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
// Output: 22
// Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
// = ((10 * (6 / (12 * -11))) + 17) + 5
// = ((10 * (6 / -132)) + 17) + 5
// = ((10 * 0) + 17) + 5
// = (0 + 17) + 5
// = 17 + 5
// = 22
 


// Constraints:
// ============
// 1 <= tokens.length <= 10^4
// tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200]





class Solution {
public:
    int toInt(string str) {
        bool isNeg = (str[0] == '-');
        int val = 0;
        for (int i = isNeg ? 1 : 0; i < str.size(); ++i)
            val = (val * 10) + (str[i] - '0');
        return (isNeg ? -1 : 1) * val;
    }

    int eval(int first, int second, string op) {
        if (op == "+")  return first + second;
        if (op == "-")  return first - second;
        if (op == "*")  return first * second;
        if (op == "/")  return first / second;
        return -1;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string token: tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int second = st.top();   st.pop();
                int first = st.top();  st.pop();
                st.push(eval(first, second, token));
            } else {
                st.push(toInt(token));
            }
        }
        return st.top();
    }
};
