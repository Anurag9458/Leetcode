struct Node{
    Node *links[26];
    bool flag=0;

    void put(char ch,Node *node){
        links[ch-'a']=node;
    }

    Node *get(char ch){
        return links[ch-'a'];
    }

    bool containskey(char ch){
        return links[ch-'a']!=NULL;
    }

    void setend(){
        flag=1;
    }

    bool isend(){
        return flag;
    }

};

class Trie{
     public:
    Node *root;
   
    Trie(){
        root=new Node();
    }

    void insert(string s){
        Node *node=root;
        for(char c:s){
            if(!node->containskey(c)){
                node->put(c,new Node());
            }
            node=node->get(c);
        }
        node->setend();
    }
    
    bool search(string s){
        Node *node=root;
        for(char c:s){
            if(node->containskey(c)){
                node=node->get(c);
            }else{
                return 0;
            }
        }
        return node->isend();
    }

};



class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        Trie trie;

        for(string s:dictionary){
            trie.insert(s);
        }

        int n=s.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            dp[i]=dp[i+1]+1;
            Node *node=trie.root;
            for(int j=i;j<n;j++){
                if(node->links[s[j]-'a']==NULL) break;
                node=node->links[s[j]-'a'];
                if(node->isend())
                dp[i]=min(dp[i],dp[j+1]);
            }
        }

    return dp[0];
    }
};