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

    vector<vector<int>>ans;

    void inorder(TreeNode *root,int sum,int tar,vector<int>&temp){
        if(!root)return;
        sum+=root->val;
        temp.push_back(root->val);
        if(!root->right && !root->left){
            if(sum==tar)
            ans.push_back(temp);
        }
        inorder(root->left,sum,tar,temp);
        inorder(root->right,sum,tar,temp);
        temp.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int tar) {
        vector<int>temp;
        int sum=0;
        inorder(root,sum,tar,temp);
        return ans;
    }
};