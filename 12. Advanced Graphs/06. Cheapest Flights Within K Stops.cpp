// Reference: https://leetcode.com/problems/cheapest-flights-within-k-stops/



// There are n cities connected by some number of flights. You are given an array flights where 
// flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city 
// toi with cost pricei.

// You are also given three integers src, dst, and k, return the cheapest price from src to dst 
// with at most k stops. If there is no such route, return -1.

 

// Example 1:
// ==========
// Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
// Output: 700
// Explanation:
// The graph is shown above.
// The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
// Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

// Example 2:
// ==========
// Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
// Output: 200
// Explanation:
// The graph is shown above.
// The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.

// Example 3:
// ==========
// Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
// Output: 500
// Explanation:
// The graph is shown above.
// The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
 


// Constraints:
// ============
// 1 <= n <= 100
// 0 <= flights.length <= (n * (n - 1) / 2)
// flights[i].length == 3
// 0 <= fromi, toi < n
// fromi != toi
// 1 <= pricei <= 10^4
// There will not be any multiple flights between two cities.
// 0 <= src, dst, k < n
// src != dst





// Approach 1

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adjLs(n); // {to, price}
        for (vector<int> flight: flights)
            adjLs[flight[0]].push_back({flight[1], flight[2]});
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        vector<int> dist(n, INT_MAX);
        minHeap.push({0, src, 0}); // {stopCount, node, price}
        dist[src] = 0;
        while (!minHeap.empty()) {
            vector<int> cur = minHeap.top();
            minHeap.pop();
            if (cur[0] <= k) {
                for (auto [next, price]: adjLs[cur[1]]) {
                    if (dist[next] > cur[2] + price) {
                        dist[next] = cur[2] + price;
                        minHeap.push({cur[0]+1, next, dist[next]});
                    }
                }
            }
        }
        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};





// Approach 2

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dp(k+2, vector<int>(n, INT_MAX));
        dp[0][src] = 0;
        for (int i = 1; i <= k+1; ++i) {
            for (int j = 0; j < n; ++j)
                dp[i][j] = dp[i-1][j];
            for (vector<int> flight: flights) {
                int from = flight[0], to = flight[1], price = flight[2];
                if (dp[i-1][from] != INT_MAX)
                    dp[i][to] = min(dp[i][to], dp[i-1][from] + price);
            }
        }
        return (dp[k+1][dst] == INT_MAX) ? -1 : dp[k+1][dst];
    }
};
