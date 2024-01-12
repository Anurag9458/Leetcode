class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
        vector<vector<int>>v(n,vector<int>(n,1e9));
        for(auto it:edges){
            v[it[0]][it[1]]=it[2];
            v[it[1]][it[0]]=it[2];
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(j!=k)
                    v[j][k]=min(v[j][k],v[j][i]+v[i][k]);
                }
            }
        }
        int maxi=1e9,ans=0;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(v[i][j]<=d)count++;
                // cout<<v[i][j]<<" ";
            }
            // cout<<endl;
            // cout<<maxi<<" "<<count<<endl; 
            if(maxi>=count){
                maxi=count;
                ans=i;
            }
        }
        return ans;
    }
};