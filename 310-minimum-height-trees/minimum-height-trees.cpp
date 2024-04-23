class Solution {

    int solve(vector<int>adj[],int node,int n){
       vector<int>visited(n,0);
       visited[node]=1;
       queue<int>q;
       q.push(node);

       int ans=0;

        while(!q.empty()){
            int n1=q.size();
            while(n1--){
                int temp=q.front();
                q.pop();
                for(int i:adj[temp]){
                    if(!visited[i]){
                        visited[i]=1;
                        q.push(i);
                    }
                }
            }
            ans++;
        }
        return ans-1;
    }



public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>ans;  
         vector<int>indegree(n);
        vector<int>adj[n];

        if(n==1){
            return {0};
        }
        for(auto it:edges){
            indegree[it[0]]++;
            indegree[it[1]]++;
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        queue<int>q;

        for(int i=0;i<n;i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }

        while(n>2){
            int n1=q.size();
            n-=n1;

            while(n1--){
                int node=q.front();
                q.pop();

                for(int i:adj[node]){
                    indegree[i]--;
                    if(indegree[i]==1){
                        q.push(i);
                    }
                }
            }
        }
       
       while(!q.empty()){
        ans.push_back(q.front());
        q.pop();
       }


        return ans;


    }
};