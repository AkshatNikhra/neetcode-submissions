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
    bool isSameTree(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        
        if(p && !q) return false;
        if(!p && q) return false;
        if(p->val != q->val) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    bool findAns(TreeNode* root, TreeNode* subRoot){
        if(!root) return false;
        if(root->val == subRoot->val){
            if(isSameTree(root, subRoot)) return true;
        }
        return findAns(root->left, subRoot) || findAns(root->right, subRoot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return findAns(root, subRoot);
    }
};
