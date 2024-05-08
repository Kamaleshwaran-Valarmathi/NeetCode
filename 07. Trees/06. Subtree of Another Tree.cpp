// Reference: https://leetcode.com/problems/subtree-of-another-tree/



// Given the roots of two binary trees root and subRoot, return true if there is a subtree of 
// root with the same structure and node values of subRoot and false otherwise.

// A subtree of a binary tree tree is a tree that consists of a node in tree and all of this 
// node's descendants. The tree tree could also be considered as a subtree of itself.

 

// Example 1:
// ==========
// Input: root = [3,4,5,1,2], subRoot = [4,1,2]
// Output: true

// Example 2:
// ==========
// Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
// Output: false
 


// Constraints:
// ============
// The number of nodes in the root tree is in the range [1, 2000].
// The number of nodes in the subRoot tree is in the range [1, 1000].
// -10^4 <= root.val <= 10^4
// -10^4 <= subRoot.val <= 10^4





// Approach 1

class Solution {
public:
    void convertRootToStr(TreeNode* root, string& str) {
        if (root != NULL) {
            str += to_string(root->val) + '$';
            convertRootToStr(root->left, str);
            convertRootToStr(root->right, str);
        }
        str += '$';
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string rootStr = "$", subRootStr = "$";
        convertRootToStr(root, rootStr);
        convertRootToStr(subRoot, subRootStr);
        return (rootStr.find(subRootStr) != string::npos);
    }
};





// Approach 2

class Solution {
public:
    bool isSameTree(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL)
            return true;
        if (root1 == NULL || root2 == NULL)
            return false;
        return (root1->val == root2->val) && isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == NULL)    return true;
        if (root == NULL)       return false;
        if (isSameTree(root, subRoot))
            return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
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
