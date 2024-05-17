// Reference: https://leetcode.ca/2016-08-09-253-Meeting-Rooms-II/



// Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], 
// return the minimum number of conference rooms required.

 

// Example 1:
// ==========
// Input: intervals = [[0,30],[5,10],[15,20]]
// Output: 2

// Example 2:
// ==========
// Input: intervals = [[7,10],[2,4]]
// Output: 1
 


// Constraints:
// ============
// 1 <= intervals.length <= 10^4
// 0 <= starti < endi <= 10^6
 




class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> start, end;
        for (int i = 0; i < intervals.size(); ++i) {
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int res = 1, cur = 1;
        int stIdx = 1, edIdx = 0;
        while (stIdx < intervals.size()) {
            (start[stIdx] <= end[edIdx]) ? (++cur, ++stIdx) : (--cur, ++edIdx);
            res = max(res, cur);
        }
        return res;
    }
};
