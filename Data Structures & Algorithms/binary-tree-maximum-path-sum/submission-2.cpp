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
    const int MIN_VALUE = -1 * 1e7;
    int ans = MIN_VALUE;
    int findAns(TreeNode* root){
        if(!root) return MIN_VALUE;

        int leftSum = findAns(root->left);
        int rightSum = findAns(root->right);

        ans = max(ans, root->val);

        ans = max({ans, root->val + leftSum + rightSum, root->val + leftSum, root->val + rightSum});

        return max({root->val, root->val + leftSum, root->val + rightSum});
    }
    int maxPathSum(TreeNode* root) {
        ans = MIN_VALUE;
        findAns(root);
        return ans;
    }
};
