class Solution {

    int row[4]={-1,1,0,0},col[4]={0,0,-1,1};

    void dfs(int i,int j,vector<vector<int>>&heights,vector<vector<int>>&temp){
        int n=heights.size(),m=heights[0].size();
        temp[i][j]=1;

        for(int a=0;a<4;a++){
            int ni=i+row[a],nj=j+col[a];
            if(ni>=0 && ni<n && nj>=0 && nj<m && heights[ni][nj]>=heights[i][j] && !temp[ni][nj]){
                dfs(ni,nj,heights,temp);
            }
        }

    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>vp(n,vector<int>(m,0));
        vector<vector<int>>va(n,vector<int>(m,0));

        vector<vector<int>>ans;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(i==0 || j==0){
                    vp[i][j]=1;
                    dfs(i,j,heights,vp);
                   
                }
                if(j==m-1 || i==n-1){
                    va[i][j]=1;
                    dfs(i,j,heights,va);
                    
                }

            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vp[i][j] && va[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;

    }
};