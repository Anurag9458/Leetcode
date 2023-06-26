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
    void solve(TreeNode* root)
    {
        if(!root)
        {
            return ;
        }
        if(root->left && root->left->left && root->val%2 == 0)
        {
            ans += root->left->left->val;
            cout<<ans<<" ";
        }
        if(root->left && root->left->right && root->val%2 == 0)
        {
            ans += root->left->right->val;
            cout<<ans<<" ";
        }
        if(root->right && root->right->right && root->val%2 == 0)
        {
            ans += root->right->right->val;
            cout<<ans<<" ";
        }
        if(root->right && root->right->left && root->val%2 == 0)
        {
            ans += root->right->left->val;
            cout<<ans<<" ";
        }
        solve(root->left);
        solve(root->right);
    }

public:
    int sumEvenGrandparent(TreeNode* root) {
        if(!root || (!root->left && !root->right))
        {
            return 0;
        }
        solve(root);
        return  ans;
    }
};