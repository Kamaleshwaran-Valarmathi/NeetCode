// Reference: https://leetcode.com/problems/network-delay-time/



// You are given a network of n nodes, labeled from 1 to n. You are also given times, a list 
// of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi 
// is the target node, and wi is the time it takes for a signal to travel from source to target.

// We will send a signal from a given node k. Return the minimum time it takes for all the n 
// nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, 
// return -1.

 

// Example 1:
// ==========
// Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
// Output: 2

// Example 2:
// ==========
// Input: times = [[1,2,1]], n = 2, k = 1
// Output: 1

// Example 3:
// ==========
// Input: times = [[1,2,1]], n = 2, k = 2
// Output: -1
 


// Constraints:
// ============
// 1 <= k <= n <= 100
// 1 <= times.length <= 6000
// times[i].length == 3
// 1 <= ui, vi <= n
// ui != vi
// 0 <= wi <= 100
// All the pairs (ui, vi) are unique. (i.e., no multiple edges.)





class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjLs(n+1);
        for (vector<int> itr: times)
            adjLs[itr[0]].push_back({itr[1], itr[2]}); // {index, dist}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<int> dist(n+1, INT_MAX);
        minHeap.push({0, k}); // {dist, index}
        dist[k] = 0;
        while (!minHeap.empty()) {
            int curIdx = minHeap.top().second;
            minHeap.pop();
            for (auto [nextIdx, nextDist]: adjLs[curIdx]) {
                if (dist[nextIdx] > dist[curIdx] + nextDist) {
                    dist[nextIdx] = dist[curIdx] + nextDist;
                    minHeap.push({dist[nextIdx], nextIdx});
                }
            }
        }
        int maxTime = *max_element(dist.begin()+1, dist.end());
        return (maxTime == INT_MAX) ? -1 : maxTime;
    }
};
