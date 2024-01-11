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


    int solve(TreeNode *root, int &ans){
        if(!root){
            return 1e9;
        }
        if(!root->right && !root->left){
            return root->val;
        }

        int temp=min(solve(root->left,ans),solve(root->right,ans));

        ans=max(ans,abs(root->val-temp));

        return min(temp,root->val);
    }

public:
    int maxAncestorDiff(TreeNode* root,int mini=INT_MAX,int maxi=INT_MIN) {
        if(!root)return maxi-mini;
        mini=min(mini,root->val),maxi=max(maxi,root->val);
        return max(maxAncestorDiff(root->left,mini,maxi),maxAncestorDiff(root->right,mini,maxi));
    }
};