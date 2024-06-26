class Solution {
public:
    int dp[46];
    int solve(int i){
        if(i==0 || i==1){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int one=solve(i-1);
        int two=solve(i-2);
        return dp[i]=one+two;
    }

    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};