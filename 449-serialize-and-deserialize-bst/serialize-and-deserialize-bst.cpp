/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {

    void solve(TreeNode *root,string &ans){
        if(!root){
            return;
        }
        
        solve(root->left,ans);
        solve(root->right,ans);
        ans+=to_string(root->val)+" ";
    }

    void simple(string s,vector<int>&temp)
    {
        stringstream ss(s);
        string word;
        while (ss >> word) {
            temp.push_back(stoi(word));
        }
    }

    TreeNode *dsolve(vector<int>&nums,int lo,int hi){
        if(nums.empty()){
            return NULL;
        }
        int val=nums[nums.size()-1];
        if(val<lo || val>hi){
            return NULL;
        }
        nums.pop_back();
        TreeNode *root=new TreeNode(val);
        root->right=dsolve(nums,val,hi);
        root->left=dsolve(nums,lo,val);
        return root;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        solve(root,ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        if(s=="")return NULL;
        vector<int>temp;
        simple(s,temp);
        return dsolve(temp,INT_MIN,INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;