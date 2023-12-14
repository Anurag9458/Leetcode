class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        vector<int>onerow,onecol,zerorow,zerocol;
        int n=grid.size(),m=grid[0].size();

        for(int i=0;i<n;i++){
            int zeror=0,oner=0;
            for(int j=0;j<m;j++){
                
                if(grid[i][j])
                oner++;
                else zeror++;
            }
            onerow.push_back(oner);
            zerorow.push_back(zeror);
          
        }

        for(int i=0;i<m;i++){
            int onec=0,zeroc=0;
            for(int j=0;j<n;j++){
                
                if(grid[j][i])
                onec++;
                else zeroc++;
            }
            onecol.push_back(onec);
            zerocol.push_back(zeroc);  
        }

        // cout<<onerow.size()<<" "<<onecol.size()<<" "<<zerorow.size()<<" "<<zerocol.size();
        
        vector<vector<int>>ans(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               
                ans[i][j]=onerow[i]+onecol[j]-zerorow[i]-zerocol[j];
                
            }
        }
        return ans;
    }
};