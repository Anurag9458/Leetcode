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

    void inorder(TreeNode* root, int maxi,int &ans){
        if(!root)return ;
        if(root->val>=maxi){
            maxi=root->val;
            ans++;
        }
        inorder(root->left,maxi,ans);
        inorder(root->right,maxi,ans);
    }

public:
    int goodNodes(TreeNode* root) {
        int maxi=root->val;
        int ans=0;
        inorder(root,maxi,ans);
        return ans;
    }
};