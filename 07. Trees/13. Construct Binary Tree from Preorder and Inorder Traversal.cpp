// Reference: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/



// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a 
// binary tree and inorder is the inorder traversal of the same tree, construct and return the 
// binary tree.

 

// Example 1:
// ==========
// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]

// Example 2:
// ==========
// Input: preorder = [-1], inorder = [-1]
// Output: [-1]
 


// Constraints:
// ============
// 1 <= preorder.length <= 3000
// inorder.length == preorder.length
// -3000 <= preorder[i], inorder[i] <= 3000
// preorder and inorder consist of unique values.
// Each value of inorder also appears in preorder.
// preorder is guaranteed to be the preorder traversal of the tree.
// inorder is guaranteed to be the inorder traversal of the tree.





class Solution {
public:
    TreeNode* helper(int& curIdx, vector<int>& preorder, unordered_map<int, int>& inorderIdx, int left, int right) {
        if (left <= right) {
            int val = preorder[curIdx++];
            TreeNode* cur = new TreeNode(val);
            cur->left = helper(curIdx, preorder, inorderIdx, left, inorderIdx[val]-1);
            cur->right = helper(curIdx, preorder, inorderIdx, inorderIdx[val]+1, right);
            return cur;
        }
        return NULL;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderIdx;
        for (int i = 0; i < inorder.size(); ++i)
            inorderIdx[inorder[i]] = i;
        int curIdx = 0;
        return helper(curIdx, preorder, inorderIdx, 0, preorder.size()-1);
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
