class Solution {

    void dfs(int node,vector<int>adj[],int &ans,vector<int>&visited){
        visited[node]=1;
        for(int i:adj[node]){
            if(i>=0){
                if(!visited[i])
                dfs(i,adj,ans,visited);
            }else{
                i=-i;
                if(!visited[i]){
                dfs(i,adj,ans,visited);
                ans++;}
            }
        }
    }

public:
    int minReorder(int n, vector<vector<int>>& arr) {
        vector<int>adj[n];
        for(auto it:arr){
            adj[it[0]].push_back(-it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans=0;
        vector<int>visited(n,0);
        dfs(0,adj,ans,visited);
        return ans;

    }
};