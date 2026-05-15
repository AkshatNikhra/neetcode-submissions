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
    int findGoodNode(TreeNode* root, int currMax){
        if(!root) return 0;

        int ans = root->val >= currMax;
        ans += findGoodNode(root->left, max(currMax, root->val));
        ans += findGoodNode(root->right, max(currMax, root->val));
        return ans; 
    }
    int goodNodes(TreeNode* root) {
        int currMax = INT_MIN;
        return findGoodNode(root, currMax);
    }
};
