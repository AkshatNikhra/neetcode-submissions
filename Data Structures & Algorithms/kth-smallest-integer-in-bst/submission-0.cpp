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
    int ans = -1;
    int K;
    void findKthSmallest(TreeNode* root){
        if(!root) return;

        findKthSmallest(root->left);
        K--;
        if(K == 0) ans = root->val;
        findKthSmallest(root->right);

    }
    int kthSmallest(TreeNode* root, int k) {
        K = k;
        findKthSmallest(root);
        return ans;
    }
};
