/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {

    void dfs(Node *node,Node *ans,unordered_map<Node*,Node*>&mp){
        
        for(Node* n:node->neighbors){
            if(!mp.count(n)){
                Node *temp=new Node(n->val);
                mp[n]=temp;
                ans->neighbors.push_back(temp);
                dfs(n,temp,mp);
            }else{
                ans->neighbors.push_back(mp[n]);
            }
        }

    }

public:
    Node* cloneGraph(Node* node) {
        if(!node)return node;
        Node *ans=new  Node(node->val);
        unordered_map<Node*,Node*>mp;
        mp[node]=ans;
        dfs(node,ans,mp);
        return ans;
    }
};