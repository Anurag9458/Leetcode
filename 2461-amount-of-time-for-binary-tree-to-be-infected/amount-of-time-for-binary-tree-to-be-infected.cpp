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

   void inorder(TreeNode *root,map<int,vector<int>>&mp){
       if(!root)return;
       if(root->left){
           mp[root->val].push_back(root->left->val);
           mp[root->left->val].push_back(root->val);
       }
       if(root->right){
           mp[root->val].push_back(root->right->val);
           mp[root->right->val].push_back(root->val);

       }
       inorder(root->left,mp);
       inorder(root->right,mp);
   }

public:
    int amountOfTime(TreeNode* root, int start) {
        map<int,vector<int>>mp;
        inorder(root,mp);
        map<int,int>visited;

        queue<pair<int,int>>q;
        int ans=0;

        q.push({0,start});
        visited[start]=1;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int node=it.second,dis=it.first;
            ans=max(dis,ans);

            for(auto it:mp[node]){
                if(!visited.count(it)){
                    visited[it]=1;
                    q.push({dis+1,it});
                }
            }
        }
        return ans;
    }
};