// Reference: https://leetcode.com/problems/detect-squares/



// You are given a stream of points on the X-Y plane. Design an algorithm that:
// - Adds new points from the stream into a data structure. Duplicate points are allowed and 
//      should be treated as different points.
// - Given a query point, counts the number of ways to choose three points from the data 
//      structure such that the three points and the query point form an axis-aligned square 
//      with positive area.

// An axis-aligned square is a square whose edges are all the same length and are either 
// parallel or perpendicular to the x-axis and y-axis.

// Implement the DetectSquares class:
// - DetectSquares() Initializes the object with an empty data structure.
// - void add(int[] point) Adds a new point point = [x, y] to the data structure.
// - int count(int[] point) Counts the number of ways to form axis-aligned squares with point 
//      point = [x, y] as described above.
 


// Example 1:
// ==========
// Input
// ["DetectSquares", "add", "add", "add", "count", "count", "add", "count"]
// [[], [[3, 10]], [[11, 2]], [[3, 2]], [[11, 10]], [[14, 8]], [[11, 2]], [[11, 10]]]
// Output
// [null, null, null, null, 1, 0, null, 2]

// Explanation
// DetectSquares detectSquares = new DetectSquares();
// detectSquares.add([3, 10]);
// detectSquares.add([11, 2]);
// detectSquares.add([3, 2]);
// detectSquares.count([11, 10]); // return 1. You can choose:
//                                //   - The first, second, and third points
// detectSquares.count([14, 8]);  // return 0. The query point cannot form a square with any points in the data structure.
// detectSquares.add([11, 2]);    // Adding duplicate points is allowed.
// detectSquares.count([11, 10]); // return 2. You can choose:
//                                //   - The first, second, and third points
//                                //   - The first, third, and fourth points
 


// Constraints:
// ============
// point.length == 2
// 0 <= x, y <= 1000
// At most 3000 calls in total will be made to add and count





// Approach 1

class DetectSquares {
public:
    unordered_map<int, unordered_map<int, int>> xPts;
    map<pair<int, int>, int> ptsCount;

    DetectSquares() {}
    
    void add(vector<int> point) {
        int x = point[0], y = point[1];
        xPts[x][y]++;
        ptsCount[{x, y}]++;
    }
    
    int count(vector<int> point) {
        int res = 0, x1 = point[0], y1 = point[1];
        for (auto [y2, cnt]: xPts[x1]) {
            int len = abs(y1 - y2);
            if (len == 0)
                continue;
            
            int x3 = x1 - len, y3 = y2;
            int x4 = x1 - len, y4 = y1;
            res += (cnt * ptsCount[{x3, y3}] * ptsCount[{x4, y4}]);

            x3 = x1 + len, y3 = y2;
            x4 = x1 + len, y4 = y1;
            res += (cnt * ptsCount[{x3, y3}] * ptsCount[{x4, y4}]);
        }
        return res;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */





// Approach 2

class DetectSquares {
public:
    vector<vector<int>> ptsCount;
    vector<pair<int, int>> pts;

    DetectSquares() {
        ptsCount.resize(1001, vector<int>(1001, 0));
    }
    
    void add(vector<int> point) {
        ++ptsCount[point[0]][point[1]];
        pts.push_back({point[0], point[1]});
    }
    
    int count(vector<int> point) {
        int res = 0, x1 = point[0], y1 = point[1];
        for (auto [x3, y3]: pts)
            if ((x1 - x3 != 0) && (abs(x1 - x3) == abs(y1 - y3)))
                res += (ptsCount[x1][y3] * ptsCount[x3][y1]);
        return res;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
