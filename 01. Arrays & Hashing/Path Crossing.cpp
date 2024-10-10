// Reference: https://leetcode.com/problems/path-crossing/



// Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit 
//      north, south, east, or west, respectively. You start at the origin (0, 0) on a 2D plane and 
//      walk on the path specified by path.

// Return true if the path crosses itself at any point, that is, if at any time you are on a location 
//      you have previously visited. Return false otherwise.

 

// Example 1:
// ==========
// Input: path = "NES"
// Output: false 
// Explanation: Notice that the path doesn't cross any point more than once.

// Example 2:
// ==========
// Input: path = "NESWW"
// Output: true
// Explanation: Notice that the path visits the origin twice.
 

// Constraints:
// ============
// 1 <= path.length <= 10^4
// path[i] is either 'N', 'S', 'E', or 'W'





class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> visited;
        pair<int, int> last_pos = {0, 0};
        visited.insert(last_pos);
        for (char dir: path) {
            if (dir == 'E' || dir == 'W') {
                last_pos.first += (dir == 'E' ? +1 : -1);
            } else {
                last_pos.second += (dir == 'N' ? +1 : -1);
            }
            if (visited.find(last_pos) != visited.end())
                return true;
            visited.insert(last_pos);
        }
        return false;
    }
};
