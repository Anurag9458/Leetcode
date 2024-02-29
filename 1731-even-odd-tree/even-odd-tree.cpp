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
    bool isEvenOddTree(TreeNode* root) {
        int j=1;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            vector<int>temp;
            set<int>st;
            int n=q.size();
            for(int i=0;i<n;i++){
                auto node=q.front();
                q.pop();
                if(j%2 && node->val%2==0){
                    return 0;
                }else if(j%2==0 && node->val%2){
                    return 0;
                } 
                temp.push_back(node->val);
                st.insert(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            // for(int i:temp)cout<<i<<" ";
            // cout<<endl; 
            vector<int>v(begin(st),end(st));
            if(j%2==0)
            reverse(begin(v),end(v));
            if(v!=temp){
                return 0;
            }
            j++;
        }
        return 1;
    }
};