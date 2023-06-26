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
    int sum = 0;
    void solve(TreeNode *root, int depth, int h)
    {
        if(!root)
        {
            return;
        }
        // cout<<depth<<" ";
        if(!root->left && !root->right && depth+1 == h)
        {
            sum += root->val;
        }
        solve(root->left, depth+1 , h);
        solve(root->right, depth+1, h);
    }


    int height(TreeNode *root)
    {
        if(!root)
        {
            return 0;
        }
        return 1 + max(height(root->left),height(root->right));
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        int h = height(root);
        cout<<h<<endl;
        solve(root, 0, h);
        return sum;
    }
};