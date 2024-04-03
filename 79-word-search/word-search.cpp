class Solution {

    bool bfs(vector<vector<char>>&grid,string &word,int a,int i,int j,vector<vector<int>>&visited){
        if(a==word.size()-1){
            return 1;
        }

        int n=grid.size(),m=grid[0].size();
        visited[i][j]=1;

        int row[4]={0,0,-1,1};
        int col[4]={-1,1,0,0};

        for(int k=0;k<4;k++){
            int ni=i+row[k],nj=j+col[k];
            if(ni>=0 && ni<n && nj>=0 && nj<m && !visited[ni][nj] && grid[ni][nj]==word[a+1]){
                if(bfs(grid,word,a+1,ni,nj,visited)){
                    return 1;
                }
            }
        }

        visited[i][j]=0;
        return 0;

    }

public:
    bool exist(vector<vector<char>>& grid, string word) {
        int n=grid.size(),m=grid[0].size();

        vector<vector<int>>visited(n,vector<int>(m,0));

       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==word[0]){
                if(bfs(grid,word,0,i,j,visited)){
                    return 1;
                }
            }
        }
       }

       return 0;


    }
};