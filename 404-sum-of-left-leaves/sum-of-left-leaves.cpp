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

    int solve(TreeNode* root,TreeNode* par){
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){
            if(par && par->left==root){
                return root->val;
            }
        }
        int left=solve(root->left,root);
        int right=solve(root->right,root);

        return left+right;
    }


public:
    int sumOfLeftLeaves(TreeNode* root) {
        TreeNode* par=NULL;
        return solve(root,par);
    }
};