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
    int ans = 0;

    int findAns(TreeNode* root){
        if(!root) return 0;

        int leftLongest = findAns(root->left);
        int rightLongest = findAns(root->right);

        ans = max(ans, 1 + leftLongest + rightLongest);

        return (1 + max(leftLongest, rightLongest));

    }
    int diameterOfBinaryTree(TreeNode* root) {
        findAns(root);
        return ans - 1;

    }
};
