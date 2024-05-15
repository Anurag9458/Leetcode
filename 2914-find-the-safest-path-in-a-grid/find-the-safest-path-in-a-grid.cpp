class Solution {

int n;
 int row[4]={-1,1,0,0},col[4]={0,0,-1,1};


    bool check(int mid,vector<vector<int>>&dis){
        queue<pair<int,int>>q;

        vector<vector<int>>visited(n,vector<int>(n,0));
        q.push({0,0});
        visited[0][0]=1;
        if(mid>dis[0][0]){
            return 0;
        }
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int i=it.first,j=it.second;

            if(i==n-1 && j==n-1){
                return 1;
            }

            for(int a=0;a<4;a++){
                int ni=i+row[a],nj=j+col[a];
                if(ni>=0 && ni<n && nj>=0 && nj<n && !visited[ni][nj]  ){
                    if(dis[ni][nj]<mid){
                        continue;
                    }
                    visited[ni][nj]=1;
                    q.push({ni,nj});
                }
            }

        }
        return 0;

    }

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
         n=grid.size();
         if(grid[0][0]){
            return 0;
         }

        queue<pair<int,int>>q;
        vector<vector<int>>dis(n,vector<int>(n,-1));
        vector<vector<int>>visited(n,vector<int>(n,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    q.push({i,j});
                    visited[i][j]=1;
                }
            }
        }

        int level=0;
       
        

        while(!q.empty()){
            int m=q.size();

            while(m--){
                auto it=q.front();
                int i=it.first,j=it.second;
                dis[i][j]=level;
                q.pop();

                for(int a=0;a<4;a++){
                    int ni=i+row[a],nj=j+col[a];

                        if(ni>=0 && ni<n && nj>=0 && nj<n && !visited[ni][nj]){
                            visited[ni][nj]=1;
                            q.push({ni,nj});
                        }

                }

            }
            level++;
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dis[i][j]<<" "; 
        //     }
        //     cout<<endl;
        // }

        int lo=0,hi=400,ans=0;

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
           
            if(check(mid,dis)){
                // cout<<mid<<" ";
                ans=mid;
                lo=mid+1;
            }else{
                hi=mid-1;
            }

        }

        return ans;

    }
};