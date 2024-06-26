// Reference: https://leetcode.com/problems/binary-tree-level-order-traversal/



// Given the root of a binary tree, return the level order traversal of its nodes' values. 
// (i.e., from left to right, level by level).

 

// Example 1:
// ==========
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]

// Example 2:
// ==========
// Input: root = [1]
// Output: [[1]]

// Example 3:
// ==========
// Input: root = []
// Output: []
 


// Constraints:
// ============
// The number of nodes in the tree is in the range [0, 2000].
// -1000 <= Node.val <= 1000





class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL)
            return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> temp;
            for (int i = 0, sz = q.size(); i < sz; ++i) {
                TreeNode* curNode = q.front();
                q.pop();
                temp.push_back(curNode->val);
                if (curNode->left != NULL)  q.push(curNode->left);
                if (curNode->right != NULL) q.push(curNode->right);
            }
            res.push_back(temp);
        }
        return res;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
