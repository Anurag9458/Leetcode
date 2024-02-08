class Solution {
    
    int dp[10004];

    int solve(int n){
        if(n==0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans=1e9;
        for(int i=1;i*i<=n;i++){
            int temp=1+solve(n-i*i);
            ans=min(ans,temp);
        }
        return dp[n]=ans;
    }
public:
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};