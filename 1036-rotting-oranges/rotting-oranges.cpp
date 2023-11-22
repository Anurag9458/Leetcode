class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<vector<int>>temp=grid;
        int row[4]={-1,1,0,0},col[4]={0,0,-1,1};
        queue<pair<int,pair<int,int>>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(temp[i][j]==2){
                    visited[i][j]=1;
                q.push({0,{i,j}});}
            }
        }
        int ans=0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int t=it.first,i=it.second.first,j=it.second.second;
            ans=max(ans,t);
            for(int a=0;a<4;a++){
                int ni=i+row[a],nj=j+col[a];
                if(ni>=0 && ni<n && nj>=0 && nj<m && !visited[ni][nj] && temp[ni][nj]==1){
                visited[ni][nj]=1;
                q.push({t+1,{ni,nj}});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && temp[i][j]==1)
                return -1;
            }
        }
        return ans;
    }
};