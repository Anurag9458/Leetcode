class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        vector<int>adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

       vector<int>v(n,0);
        queue<int>q;
        q.push(s);
        v[s]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(node==d){
                return 1;
            }
            for(int it:adj[node]){
                if(!v[it]){
                    q.push(it);
                    v[it]=1;
                }
            }
        }

        return 0;

    }
};