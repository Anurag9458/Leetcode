class Solution {
    
   

    int solve(int i,int j,vector<vector<int>>&img,int n,int m,int row[],int col[]){
        int count=1,sum=img[i][j];
        for(int a=0;a<8;a++){
            int ni=row[a]+i,nj=j+col[a];
            if(ni>=0 && ni<n && nj>=0 && nj<m){
                sum+=img[ni][nj];
                count++;
                // cout<<ni<<" "<<nj<<endl;
            }
        }
        // cout<<sum<<" "<<count<<endl; 
        return sum/count;
    }

public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size(),m=img[0].size();
        vector<vector<int>>ans=img;
         int row[8]={-1,1,0,0,-1,1,1,-1},col[8]={0,0,-1,1,-1,1,-1,1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=solve(i,j,img,n,m,row,col);
            }
        }
        return ans;
    }
};