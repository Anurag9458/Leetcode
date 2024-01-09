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
class Node{
    public:
    int mini,maxi,sum;
    Node(int mini,int maxi,int sum){
        this->mini=mini;
        this->maxi=maxi;
        this->sum=sum;
    }
};


class Solution {

    // bool bst(TreeNode *root,int mini,int maxi){
    //     if(!root)return 1;
    //     if(root->val>=maxi || root->val<=mini){
    //         return 0;
    //     }
    //     return bst(root->left,mini,root->val)&&bst(root->right,root->val,maxi);
    // }

    // void sum(TreeNode *root,int &temp){
    //     if(!root)return;
    //     temp+=root->val;
    //     sum(root->left,temp);
    //     sum(root->right,temp);
    // }


    // void solve(TreeNode *root,int &ans){
    //     if(!root)return ;
    //     if(bst(root,INT_MIN,INT_MAX)){
    //         int temp=0;
    //         sum(root,temp);
    //         ans=max(ans,temp);
    //     }
    //     solve(root->left,ans);
    //     solve(root->right,ans);
    // }


    Node solve(TreeNode *root){
        if(!root){
            return Node(INT_MAX,INT_MIN,0);
        }
        auto left=solve(root->left);
        auto right=solve(root->right);
        // cout<<left.maxi<<" "<<root->val<<" "<<right.mini<<endl;
        if(left.maxi<root->val && root->val<right.mini){
            // cout<<root->val<<" ";
            ans=max(ans,root->val+left.sum+right.sum);
            return Node(min(left.mini,root->val),max(right.maxi,root->val),(root->val+left.sum+right.sum));
        }
        return Node(INT_MIN,INT_MAX,max(left.sum,right.sum));
    }

public:
    int ans;
    int maxSumBST(TreeNode* root) {
       
        solve(root);
        if(ans<0)return 0;
        return ans;
    }
};