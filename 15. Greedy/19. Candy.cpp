// Reference: https://leetcode.com/problems/candy/



// There are n children standing in a line. Each child is assigned a rating value given in the 
// integer array ratings.

// You are giving candies to these children subjected to the following requirements:
// - Each child must have at least one candy.
// - Children with a higher rating get more candies than their neighbors.

// Return the minimum number of candies you need to have to distribute the candies to the children.

 

// Example 1:
// ==========
// Input: ratings = [1,0,2]
// Output: 5
// Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

// Example 2:
// ==========
// Input: ratings = [1,2,2]
// Output: 4
// Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
// The third child gets 1 candy because it satisfies the above two conditions.
 


// Constraints:
// ============
// n == ratings.length
// 1 <= n <= 2 * 10^4
// 0 <= ratings[i] <= 2 * 10^4
 




// Approach 1

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        for (int i = 1; i < n; ++i)
            if (ratings[i] > ratings[i-1])
                candies[i] = candies[i-1] + 1;
        for (int i = n-2; i >= 0; --i)
            if (ratings[i] > ratings[i+1])
                candies[i] = max(candies[i], candies[i+1] + 1);
        return accumulate(candies.begin(), candies.end(), 0);
    }
};





// Approach 2

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candies = 1, up = 0, down = 0, peak = 0;
        for (int prev = 0, cur = 1; cur < n; ++prev, ++cur) {
            if (ratings[prev] < ratings[cur]) {
                peak = up + 1, up = up + 1, down = 0;
                candies += 1 + up;
            } else if (ratings[prev] == ratings[cur]) {
                peak = 0, up = 0, down = 0;
                candies += 1;
            } else {
                up = 0, down = down + 1;
                candies += 1 + (down - (peak >= down));
            }
        }
        return candies;
    }
};
