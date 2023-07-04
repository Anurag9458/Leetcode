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
        inorder(root,mp,0,0);

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