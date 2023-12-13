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

    int ans=0;

    void inorder(TreeNode *root,long long sum,int &tar){
        if(!root)return;
        sum+=root->val;
        if(sum==tar){
            ans++;
        }
        inorder(root->left,sum,tar);
        inorder(root->right,sum,tar);

    }

public:
    int pathSum(TreeNode* root, int tar) {
        long long sum=0;
        if(root){
            inorder(root,sum,tar);
            pathSum(root->left,tar);
            pathSum(root->right,tar);
        }
        return ans;
    }
};