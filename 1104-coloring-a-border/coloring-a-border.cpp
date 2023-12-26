class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& matrix, int r, int c, int nc) {
    int n=matrix.size(),m=matrix[0].size();
    vector<vector<int>>ans=matrix;
    vector<vector<int>>visited(n,vector<int>(m,0));
    int oc=matrix[r][c];

    int row[4]={-1,1,0,0},col[4]={0,0,-1,1};

    queue<pair<int,int>>q;
    
    visited[r][c]=1;
    q.push({r,c});
    ans[r][c]=nc;
    while(!q.empty()){

        auto it=q.front();
        q.pop();
        int i=it.first,j=it.second;   
        ans[i][j]=nc;
        int count=0;     
        for(int a=0;a<4;a++){
            int ni=i+row[a],nj=j+col[a];
            if(ni>=0 && ni<n && nj>=0 && nj<m && matrix[ni][nj]==oc){
                count++;
                if(! visited[ni][nj]){
                q.push({ni,nj});
                visited[ni][nj]=1;
                }
            }
        }
        if(count==4)ans[i][j]=oc;
    }

    return ans;

    }
};