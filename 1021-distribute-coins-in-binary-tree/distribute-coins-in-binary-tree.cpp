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
    int ans=0;

    int solve(TreeNode *root){
        if(!root){
            return 0;
        }
        int left=0,right=0;
         left=solve(root->left);
         right=solve(root->right);
        ans+=abs(left)+abs(right);
        return (left+right+root->val-1);
    }

public:
    int distributeCoins(TreeNode* root) {
        solve(root);
        return ans;
    }
};