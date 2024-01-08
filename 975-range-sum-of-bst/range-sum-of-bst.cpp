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
    void solve(TreeNode *root,int &lo,int &hi){
        if(!root){
            return ;
        }

        if(root->val>=lo && root->val<=hi)
        ans+=root->val;
        solve(root->left,lo,hi);
        solve(root->right,lo,hi);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        solve(root,low,high);
        return ans;
    }
};