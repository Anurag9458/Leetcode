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
    int ans,maxi=-1;

    void solve(TreeNode *root,int d){
        if(!root)return;
        if(d>maxi){
            maxi=d;
            ans=root->val;
        }
        solve(root->left,d+1);
        solve(root->right,d+1);
    }

public:
    int findBottomLeftValue(TreeNode* root) {
        // int ans;
        // queue<TreeNode*>q;
        // q.push(root);
        // while(!q.empty()){
        //     int n=q.size();
        //     ans=q.front()->val;
        //     while(n--){
        //         auto it=q.front();
        //         q.pop();
        //         if(it->left){
        //             q.push(it->left);
        //         }
        //         if(it->right){
        //             q.push(it->right);
        //         }
        //     }
        // }
        
        solve(root,0);

        return ans;
    }
};