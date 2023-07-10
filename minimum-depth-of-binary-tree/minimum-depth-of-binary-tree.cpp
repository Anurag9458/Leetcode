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
    int ans = 1e9;

    int solve(TreeNode *root,int count){
        if(!root){
            return 0;
        }
        if(!root->left && !root->right)
        ans = min(ans, count);
        else{
            count++;
        }
        return 1 + max(solve(root->left,count), solve(root->right,count));
    }

public:
    int minDepth(TreeNode* root) {
        if(!root)return 0;
        int h = solve(root, 1);
        return ans;

    }
};