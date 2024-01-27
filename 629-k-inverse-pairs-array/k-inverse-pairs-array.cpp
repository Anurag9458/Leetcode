class Solution {
    
    int dp[1001][1001];
    int mod=1e9+7;

    int solve(int n,int k){
          
        if(n==0){
            return 0;
        }

        if(k==0){
            return 1;
        }

        if(dp[n][k]!=-1){
            return dp[n][k];
        }
        int count=0;

        for(int i=0;i<=min(k,n-1);i++){
            count=(count+solve(n-1,k-i)%mod)%mod;
        }

        return dp[n][k]=count%mod;
    }

public:
    int kInversePairs(int n, int k) {
      memset(dp,-1,sizeof(dp));
      return solve(n,k);
    }
};