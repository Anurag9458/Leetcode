class Solution {

    long long int dp[55][55][55];

    long long int mod=1e9+7;

    int solve(int i,int j,int n,int m,int moves){
        if(i<0 || i>=n || j<0 ||j>=m){
            return 1;
        }
        if(moves<=0){
            return 0;
        }

        if(dp[i][j][moves]!=-1){
            return dp[i][j][moves];
        }

        int up=solve(i-1,j,n,m,moves-1);
        int down=solve(i+1,j,n,m,moves-1);
        int left=solve(i,j-1,n,m,moves-1);
        int right=solve(i,j+1,n,m,moves-1);

        return dp[i][j][moves]=(up%mod + down%mod + left%mod + right%mod)%mod;
    }


public:
    int findPaths(int n, int m, int maxi, int r, int c) {
        
        memset(dp,-1,sizeof(dp));
        return solve(r,c,n,m,maxi);
        
    }
};
