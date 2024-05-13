// Reference:https://leetcode.com/problems/reconstruct-itinerary/



// You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the 
// departure and the arrival airports of one flight. Reconstruct the itinerary in order and 
// return it.

// All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin 
// with "JFK". If there are multiple valid itineraries, you should return the itinerary that 
// has the smallest lexical order when read as a single string.

// - For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].

// You may assume all tickets form at least one valid itinerary. You must use all the tickets 
// once and only once.

 

// Example 1:
// ==========
// Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
// Output: ["JFK","MUC","LHR","SFO","SJC"]

// Example 2:
// ==========
// Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
// Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
// Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but 
//      it is larger in lexical order.
 


// Constraints:
// ============
// 1 <= tickets.length <= 300
// tickets[i].length == 2
// fromi.length == 3
// toi.length == 3
// fromi and toi consist of uppercase English letters.
// fromi != toi





class Solution {
public:
    void dfs(string cur, unordered_map<string, vector<string>>& adjLs, vector<string>& iter) {
        while (!adjLs[cur].empty()) {
            string next = adjLs[cur].back();
            adjLs[cur].pop_back();
            dfs(next, adjLs, iter);
        }
        iter.push_back(cur);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adjLs;
        for (vector<string> ticket: tickets)
            adjLs[ticket[0]].push_back(ticket[1]);
        for (auto& [_, dest]: adjLs)
            sort(dest.begin(), dest.end(), greater<string>());
        vector<string> iter;
        dfs("JFK", adjLs, iter);
        reverse(iter.begin(), iter.end());
        return iter;
    }
};
