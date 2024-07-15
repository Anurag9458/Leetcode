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
public:
    TreeNode* createBinaryTree(vector<vector<int>>& arr) {
        unordered_map<int,TreeNode*>mp;
        set<int>st;

        for(auto it:arr){
            int par=it[0],child=it[1],left=it[2];

            if(!mp.count(par)){
                mp[par]=new TreeNode(par);
            }

            if(!mp.count(child)){
                mp[child]=new TreeNode(child);
            }

            if(left){
                mp[par]->left=mp[child];
            }else{
                mp[par]->right=mp[child];
            }

            st.insert(child);

        }

        for(auto it:arr){
            if(st.find(it[0])==st.end()){
                return mp[it[0]];
            }
        }

        return NULL;

    }
};