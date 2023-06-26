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
    int deepestLeavesSum(TreeNode* root) {
        if(!root)return 0;
        vector<vector<int>>v;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            vector<int>temp;
            for(int i = 0 ;i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            v.push_back(temp);
        }
        int ans = 0;
        int n1 = v.size();
        int n2 = v[n1 - 1].size();
        for(int i = 0; i < n2; i++)
        {
            ans += v[n1-1][i];
        }
        return ans;
    }
};