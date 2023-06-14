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

    //Here we are dfs traversal 
    void dfs(TreeNode* root,TreeNode* &prev,int &ans)
    {
        if(!root)return;
        dfs(root->left,prev,ans);
        //Finding absolute diff b/w prev and root
        if(prev!=NULL)ans=min(ans,abs(prev->val-root->val));
        prev=root;
        dfs(root->right,prev,ans);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        int ans=1e9;
        TreeNode* prev=NULL;
        dfs(root,prev,ans);
        return ans;
    }
};