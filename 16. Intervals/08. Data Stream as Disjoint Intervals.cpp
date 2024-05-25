// Reference: https://leetcode.com/problems/data-stream-as-disjoint-intervals/



// Given a data stream input of non-negative integers a1, a2, ..., an, summarize the numbers 
// seen so far as a list of disjoint intervals.

// Implement the SummaryRanges class:
// - SummaryRanges() Initializes the object with an empty stream.
// - void addNum(int value) Adds the integer value to the stream.
// - int[][] getIntervals() Returns a summary of the integers in the stream currently as a list 
//      of disjoint intervals [starti, endi]. The answer should be sorted by starti.
 


// Example 1:
// ==========
// Input
// ["SummaryRanges", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", 
//      "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals"]
// [[], [1], [], [3], [], [7], [], [2], [], [6], []]
// Output
// [null, null, [[1, 1]], null, [[1, 1], [3, 3]], null, [[1, 1], [3, 3], [7, 7]], null, 
//      [[1, 3], [7, 7]], null, [[1, 3], [6, 7]]]

// Explanation
// SummaryRanges summaryRanges = new SummaryRanges();
// summaryRanges.addNum(1);      // arr = [1]
// summaryRanges.getIntervals(); // return [[1, 1]]
// summaryRanges.addNum(3);      // arr = [1, 3]
// summaryRanges.getIntervals(); // return [[1, 1], [3, 3]]
// summaryRanges.addNum(7);      // arr = [1, 3, 7]
// summaryRanges.getIntervals(); // return [[1, 1], [3, 3], [7, 7]]
// summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
// summaryRanges.getIntervals(); // return [[1, 3], [7, 7]]
// summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
// summaryRanges.getIntervals(); // return [[1, 3], [6, 7]]
 


// Constraints:
// ============
// 0 <= value <= 10^4
// At most 3 * 10^4 calls will be made to addNum and getIntervals.
// At most 10^2 calls will be made to getIntervals.
 


// Follow up: What if there are lots of merges and the number of disjoint intervals is small 
// compared to the size of the data stream?
 




// Approach 1

class SummaryRanges {
public:
    set<int> nums;

    SummaryRanges() {}
    
    void addNum(int value) {
        nums.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        if (nums.empty())
            return {};
        
        vector<vector<int>> res;
        int start = *(nums.begin()), end = *(nums.begin());
        for (auto itr = ++(nums.begin()); itr != nums.end(); ++itr) {
            if (*itr - end == 1) {
                end = *itr;
            } else {
                res.push_back({start, end});
                start = end = *itr;
            }
        }
        res.push_back({start, end});
        return res;
    }
};





// Approach 2

class SummaryRanges {
public:
    unordered_set<int> visited;
    set<pair<int, int>> ranges;

    SummaryRanges() {}

    void merge(auto& prev, auto& cur) {
        if (cur->first - prev->second == 1) {
            auto [prevStart, prevEnd] = *prev;
            auto [curStart, curEnd] = *cur;
            ranges.insert({prevStart, curEnd});
            ranges.erase(prev);
            ranges.erase(cur);
            cur = ranges.find({prevStart, curEnd});
        }
    }
    
    void addNum(int value) {
        if (visited.find(value) != visited.end())
            return;
        
        ranges.insert({value, value});
        visited.insert(value);

        auto curItr = ranges.find({value, value});
        if (curItr != ranges.begin()) {
            auto prevItr = --(ranges.find({value, value}));
            merge(prevItr, curItr);
        }
        if (curItr != ranges.end()) {
            auto nextItr = ++(ranges.find({curItr->first, curItr->second}));
            merge(curItr, nextItr);
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (auto [start, end]: ranges)
            res.push_back({start, end});
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
