// Reference: https://leetcode.com/problems/balanced-binary-tree/



// Given a binary tree, determine if it is height-balanced

 

// Example 1:
// ==========
// Input: root = [3,9,20,null,null,15,7]
// Output: true

// Example 2:
// ==========
// Input: root = [1,2,2,3,3,null,null,4,4]
// Output: false

// Example 3:
// ==========
// Input: root = []
// Output: true
 


// Constraints:
// ============
// The number of nodes in the tree is in the range [0, 5000].
// -10^4 <= Node.val <= 10^4





class Solution {
public:
    int getHeight(TreeNode* root, bool& balancedFlag) {
        if (root == NULL)
            return 0;
        int leftHt = getHeight(root->left, balancedFlag);
        int rightHt = getHeight(root->right, balancedFlag);
        if (abs(leftHt - rightHt) > 1)
            balancedFlag = false;
        return max(leftHt, rightHt) + 1;
    }

    bool isBalanced(TreeNode* root) {
        bool balancedFlag = true;
        getHeight(root, balancedFlag);
        return balancedFlag;
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
