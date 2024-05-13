// Reference: https://leetcode.com/problems/min-cost-to-connect-all-points/



// You are given an array points representing integer coordinates of some points on a 2D-plane, 
// where points[i] = [xi, yi].

// The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between 
// them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

// Return the minimum cost to make all points connected. All points are connected if there is 
// exactly one simple path between any two points.

 

// Example 1:
// ==========
// Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
// Output: 20
// Explanation: 
// We can connect the points as shown above to get the minimum cost of 20.
// Notice that there is a unique path between every pair of points.

// Example 2:
// ==========
// Input: points = [[3,12],[-2,5],[-4,1]]
// Output: 18
 


// Constraints:
// ============
// 1 <= points.length <= 1000
// -10^6 <= xi, yi <= 10^6
// All pairs (xi, yi) are distinct.





class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), sum = 0, pointsConnected = 0;
        vector<bool> visited(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, 0}); // {dist, index}
        while (pointsConnected < n) {
            auto [dist, index] = minHeap.top();
            minHeap.pop();
            if (!visited[index]) {
                visited[index] = true;
                sum += dist;
                ++pointsConnected;
                vector<int> pt1 = points[index];
                for (int i = 0; i < n; ++i) {
                    if (!visited[i]) {
                        vector<int> pt2 = points[i];
                        int dist = abs(pt1[0] - pt2[0]) + abs(pt1[1] - pt2[1]);
                        minHeap.push({dist, i});
                    }
                }
            }
        }
        return sum;
    }
};
