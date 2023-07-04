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

    void inorder(TreeNode *root, map<int, map<int, multiset<int>>>&mp,int v,int l){
        if(!root){
            return;
        }
        inorder(root->left, mp, v-1 , l+1);
        mp[v][l].insert(root->val);
        inorder(root->right, mp, v+1, l+1);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        map<int, map<int, multiset<int>>>mp;
        // inorder(root,mp,0,0);
        queue<pair<TreeNode*, pair<int,int>>>q;
        q.push({root, {0,0}});
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            TreeNode *node = temp.first;
            int v = temp.second.first, l = temp.second.second;
            
            mp[v][l].insert(node->val);
            if(node->left){
                q.push({node->left, {v-1, l+1}});
            }
            if(node->right){
                q.push({node->right, {v+1 , l+1}});
            }
        }

        for(auto it:mp){
            vector<int> temp;
            for(auto i : it.second){
                for(auto i1 : i.second){
                    temp.push_back(i1);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};