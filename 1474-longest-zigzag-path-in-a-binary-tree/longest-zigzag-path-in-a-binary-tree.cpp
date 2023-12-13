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

    void solve(TreeNode* root,int dir,int &temp){
        if(!root)return;
        if(dir){
            if(root->right)
            temp++;
            solve(root->right,!dir,temp);
        }else if(!dir){
            if(root->left)
            temp++;
            solve(root->left,!dir,temp);
        }

    }

public:
    int longestZigZag(TreeNode* root) {
        int dir=1;
        if(root){
            int temp=0,temp1=0,left=0;
            solve(root,dir,temp);
            solve(root,left,temp1);
            longestZigZag(root->left);
            longestZigZag(root->right);
            ans=max(temp,ans);
            ans=max(temp1,ans);
        }

        return ans;

    }
};