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

class Solution {
public:
    // int calculateDepth(TreeNode* root){
    //     if(!root) return 0;
    //     int leftDepth = calculateDepth(root->left);
    //     int rightDepth = calculateDepth(root->right);
    //     return (1 + max(leftDepth, rightDepth));
    // }
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return (1 + max(leftDepth, rightDepth));
    }
};
