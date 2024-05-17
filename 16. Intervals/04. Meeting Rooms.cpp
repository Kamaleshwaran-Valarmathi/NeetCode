// Reference: https://leetcode.ca/2016-08-08-252-Meeting-Rooms/



// Given an array of meeting time intervals where intervals[i] = [starti, endi], determine if 
// a person could attend all meetings.

 

// Example 1:
// ==========
// Input: intervals = [[0,30],[5,10],[15,20]]
// Output: false

// Example 2:
// ==========
// Input: intervals = [[7,10],[2,4]]
// Output: true
 


// Constraints:
// ============
// 0 <= intervals.length <= 10^4
// intervals[i].length == 2
// 0 <= starti < endi <= 10^6
 




class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }

    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        for (int i = 1; i < intervals.size(); ++i)
            if (intervals[i-1][1] > intervals[i][0])
                return false;
        return true;
    }
};
