// Reference: https://leetcode.com/problems/largest-rectangle-in-histogram/



// Given an array of integers heights representing the histogram's bar height where the width 
// of each bar is 1, return the area of the largest rectangle in the histogram.

 

// Example 1:
// ==========
// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.

// Example 2:
// ==========
// Input: heights = [2,4]
// Output: 4
 


// Constraints:
// ============
// 1 <= heights.length <= 10^5
// 0 <= heights[i] <= 10^4





class Solution {
public:
    vector<int> getLeftMin(vector<int>& heights) {
        vector<int> leftMin(heights.size());
        stack<int> st;
        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            leftMin[i] = (st.empty() ? -1 : st.top());
            st.push(i);
        }
        return leftMin;
    }

    vector<int> getRightMin(vector<int>& heights) {
        vector<int> rightMin(heights.size());
        stack<int> st;
        for (int i = heights.size()-1; i >= 0; --i) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            rightMin[i] = (st.empty() ? heights.size() : st.top());
            st.push(i);
        }
        return rightMin;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> leftMin = getLeftMin(heights);
        vector<int> rightMin = getRightMin(heights);
        int res = 0;
        for (int i = 0; i < heights.size(); ++i)
            res = max(res, heights[i] * (rightMin[i] - leftMin[i] - 1));
        return res;
    }
};
