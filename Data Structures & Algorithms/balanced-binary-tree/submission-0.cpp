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
    bool ans = true;
    int findAns(TreeNode* root){
        if(!root) return 0;
        int leftDepth = findAns(root->left);
        int rightDepth = findAns(root->right);
        if(abs(leftDepth - rightDepth) > 1) {
            ans = false;
        }
        return (1 + max(leftDepth, rightDepth));
    }
    bool isBalanced(TreeNode* root) {
        findAns(root);
        return ans;
    }
};
