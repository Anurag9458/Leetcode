class Solution {

    bool solve(vector<vector<int>>&grid,vector<int>&visited,
    vector<int>&pvisited,vector<int>&check,int i)
    {
        visited[i]=pvisited[i]=1;
        check[i]=0;
        for(int a:grid[i])
        {
            if(!visited[a])
            {
                if(solve(grid,visited,pvisited,check,a))return 1;
            }
            else if(pvisited[a])return 1;
        }
        check[i]=1;
        pvisited[i]=0;
        return 0;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>visited(n,0),pvisited(n,0),ans,check(n,0);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                solve(grid,visited,pvisited,check,i);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(check[i])ans.push_back(i);
        }
        return ans;

    }
};