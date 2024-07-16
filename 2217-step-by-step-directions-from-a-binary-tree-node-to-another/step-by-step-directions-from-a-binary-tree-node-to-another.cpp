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

TreeNode* LCA(TreeNode* root, int s, int d){
    if(!root){
        return NULL;
    }

    if(root->val==s || root->val==d){
        return root;
    }

    TreeNode* left=LCA(root->left,s,d);
    TreeNode* right=LCA(root->right,s,d);

    if(left && right){
        return root;
    }

    return left?left:right;
}

bool solve(TreeNode* root,int key,string &s){
    if(!root){
        return 0;
    }

    if(root->val==key){
        return 1;
    }

    s.push_back('L');
    if(solve(root->left,key,s)){
        return 1;
    }

    s.pop_back();

    s.push_back('R');
    if(solve(root->right,key,s)){
        return 1;
    }

    s.pop_back();

    return 0;

}

public:
    string getDirections(TreeNode* root, int s, int d) {
        TreeNode* lca=LCA(root,s,d);

        string ls,ld;

        solve(lca,s,ls);
        solve(lca,d,ld);

        string ans;

        for(char c:ls){
            ans.push_back('U');
        }

        ans+=ld;

        return ans;
    }
};