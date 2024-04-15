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

    void solve(TreeNode *root,vector<string>&v,string s){
        if(!root){
            return;
        }
        s.push_back('0'+root->val);
        if(!root->left && !root->right){
            v.push_back(s);
        }
        solve(root->left,v,s);
        solve(root->right,v,s);
    }

public:
    int sumNumbers(TreeNode* root) {
        vector<string>v;
        string temp;
        solve(root,v,temp);

        int ans=0;
        for(string s:v){
            int temp=stoi(s);
            ans+=temp;
        }

        return ans;

    }
};