class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int>indegree(n,0),adj[n];
        for(int i=0;i<p.size();i++)
        adj[p[i][0]].push_back(p[i][1]);
        for(int i=0;i<n;i++)
        {
            for(int a:adj[i])indegree[a]++;
        }
        queue<int>q;
        int count=0;
        for(int i=0;i<n;i++)
        {
            cout<<indegree[i]<<" ";
            if(!indegree[i])
            q.push(i);
        }
        while(!q.empty())
        {
            int temp=q.front();q.pop();
            count++;
            for(int a:adj[temp]){indegree[a]--;
            if(!indegree[a])
            q.push(a);}
        }
        return count==n;
    }
};