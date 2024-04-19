class Solution {

    void solve(vector<vector<char>>&grid,vector<vector<int>>&visited,int i,int j)
    {
        int n=grid.size(),m=grid[0].size();
        visited[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        vector<int>v1{-1,1,0,0},v2{0,0,-1,1};
        while(!q.empty())
        {
            int temp1=q.front().first,temp2=q.front().second;
            q.pop();
            for(int a=0;a<4;a++)
            {
                
                    int ni=temp1+v1[a],nj=temp2+v2[a];
                    if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]=='1' && !visited[ni][nj])
                    {
                        visited[ni][nj]=1;
                        q.push({ni,nj});
                    }
                
            }
        }
    }


public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && grid[i][j]=='1')
                {
                    
                    solve(grid,visited,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};