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

    void solve(TreeNode *root,set<string>&temp,string s){
        if(!root){
            return;
        }
        s.push_back('a'+root->val);
        if(!root->left && !root->right){
            string a=s;
            reverse(begin(a),end(a));
            temp.insert(a);
        }
        solve(root->left,temp,s);
        solve(root->right,temp,s);
    }

public:
    string smallestFromLeaf(TreeNode* root) {
        set<string>temp;
        string s;
        solve(root,temp,s);
        return *temp.begin();
    }
};