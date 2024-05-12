// Reference: https://leetcode.ca/2016-08-17-261-Graph-Valid-Tree/



// Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair 
// of nodes), write a function to find the number of connected components in an undirected 
// graph.

// Note: You can assume that no duplicate edges will appear in edges. Since all edges are 
// undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges



// Example 1:
// ==========
// Input: n = 5 and edges = [[0, 1], [1, 2], [3, 4]]
// Output: 2

// Example 2:
// ==========
// Input: n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]]
// Output:  1



// Constraints:
// ============
// 1 <= n <= 2000
// 1 <= edges.length <= 5000
// edges[i].length == 2
// 0 <= ai <= bi < n
// ai != bi
// There are no repeated edges.





class Solution {
public:
    int find(int node, vector<int>& parent) {
        if (parent[node] != node)
            parent[node] = find(parent[node], parent);
        return parent[node];
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
        for (vector<int> edge: edges) {
            int parentA = find(edge[0], parent);
            int parentB = find(edge[1], parent);
            parent[parentA] = parentB;
        }
        int compCount = 0;
        for (int i = 0; i < n; ++i)
            compCount += (i == find(i, parent));
        return compCount;
    }
};
