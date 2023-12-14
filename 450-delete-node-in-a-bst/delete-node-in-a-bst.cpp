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

    TreeNode *find(TreeNode *root){
        if(root->right==NULL)return root;
        return find(root->right);
    }

    TreeNode *solve(TreeNode *root){
        if(root->left==NULL){
            return root->right;
        }else if(!root->right)
        return root->left;

        TreeNode *right=root->right;
        TreeNode *lastright=find(root->left);
        lastright->right=right;
        return root->left;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {

     if(!root)return root;

     if(root->val==key)return solve(root);
     TreeNode *temp=root;

     while(temp){
         if(temp->val>key){
             if(temp->left && temp->left->val==key){
                 temp->left=solve(temp->left);
                 break;
             }else{
                 temp=temp->left;
             }
         }else{
             if(temp->right && temp->right->val==key){
                 temp->right=solve(temp->right);
                 break;
             }else{
                 temp=temp->right;
             }
         }
     }
        return root;
    }
};