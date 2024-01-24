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

    bool check(unordered_map<int,int>&mp){
        int  count=0;
        for(auto it:mp){
            if(it.second%2){
                count++;
            }
        }

        return count<=1;
    }

    int ans=0;

    void solve(TreeNode* root,unordered_map<int,int>temp){
        if(!root){
            return;
        }

        if(!root->left && !root->right){
            temp[root->val]++;
            if(check(temp)){
                ans++;
            }
            return;
        }

        temp[root->val]++;
        solve(root->left,temp);
        solve(root->right,temp);

    }


public:
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int>temp;
        if(!root->left && !root->right){
            return 1;
        }
        solve(root,temp);

        return ans;
    }
};