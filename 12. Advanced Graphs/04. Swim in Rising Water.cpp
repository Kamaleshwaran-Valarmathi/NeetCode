// Reference: https://leetcode.com/problems/swim-in-rising-water/



// You are given an n x n integer matrix grid where each value grid[i][j] represents the 
// elevation at that point (i, j).

// The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim 
// from a square to another 4-directionally adjacent square if and only if the elevation of 
// both squares individually are at most t. You can swim infinite distances in zero time. Of 
// course, you must stay within the boundaries of the grid during your swim.

// Return the least time until you can reach the bottom right square (n - 1, n - 1) if you 
// start at the top left square (0, 0).

 

// Example 1:
// ==========
// Input: grid = [[0,2],[1,3]]
// Output: 3
// Explanation:
// At time 0, you are in grid location (0, 0).
// You cannot go anywhere else because 4-directionally adjacent neighbors have a higher 
//      elevation than t = 0.
// You cannot reach point (1, 1) until time 3.
// When the depth of water is 3, we can swim anywhere inside the grid.

// Example 2:
// ==========
// Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
// Output: 16
// Explanation: The final route is shown.
// We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
 


// Constraints:
// ============
// n == grid.length
// n == grid[i].length
// 1 <= n <= 50
// 0 <= grid[i][j] < n^2
// Each value grid[i][j] is unique





class Solution {
public:
    vector<int> X = {0, 0, 1, -1};
    vector<int> Y = {1, -1, 0, 0};

    bool isValid(int x, int y, int n) {
        return (x >= 0 && x < n) && (y >= 0 && y < n);
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), maxTime = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        minHeap.push({grid[0][0], 0, 0}); // {time, X, Y}
        visited[0][0] = true;
        while (!minHeap.empty()) {
            vector<int> cur = minHeap.top();
            minHeap.pop();
            maxTime = max(maxTime, cur[0]);
            if (cur[1] == n-1 && cur[2] == n-1)
                return maxTime;
            for (int i = 0; i < X.size(); ++i) {
                int nextX = cur[1] + X[i], nextY = cur[2] + Y[i];
                if (isValid(nextX, nextY, n) && !visited[nextX][nextY]) {
                    visited[nextX][nextY] = true;
                    minHeap.push({grid[nextX][nextY], nextX, nextY});
                }
            }
        }
        return -1;
    }
};
