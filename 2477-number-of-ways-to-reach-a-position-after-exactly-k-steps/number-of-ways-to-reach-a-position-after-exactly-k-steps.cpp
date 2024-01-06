class Solution {
    int mod=1e9+7;
    long long int dp[3005][1005];
    int solve(int i,int j,int k){
        if(k==0){
            return i==j;
        }
        
        if(dp[999+i][k]!=-1){
            return dp[999+i][k];
        }
        int pos=solve(i+1,j,k-1)%mod;
        int neg=solve(i-1,j,k-1)%mod;
       
        dp[999+i][k]=(pos+neg)%mod;
        return dp[999+i][k];
    }

public:
    int numberOfWays(int i, int j, int k) {
     memset(dp,-1,sizeof(dp));
     return solve(i,j,k);   
    }
};