class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
     int n=grid.size(),m=grid[0].size();

     int ans=0;
     int row[4]={0,0,-1,1},col[4]={-1,1,0,0};
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]){
                for(int a=0;a<4;a++){
                    int ni=i+row[a],nj=j+col[a];
                    if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]){
                        continue;
                    }else{
                        ans++;
                    }
                }
            }
        }
     }
        return ans;
    }
};