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

    TreeNode* tree(int lo,int hi,vector<int>&temp){
        if(lo>hi){
            return NULL;}
            int mid=lo+(hi-lo)/2;
            TreeNode *root=new TreeNode(temp[mid]);
            root->left=tree(lo,mid-1,temp);
            root->right=tree(mid+1,hi,temp);
            return root;
    }

    void solve(TreeNode *root,vector<int>&temp){
        if(!root){
            return;
        }
        
        solve(root->left,temp);
        temp.push_back(root->val);
        solve(root->right,temp);

    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>temp;

        solve(root,temp);

        return tree(0,temp.size()-1,temp);

    }
};