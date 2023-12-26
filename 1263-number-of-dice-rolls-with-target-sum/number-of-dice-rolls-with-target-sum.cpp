class Solution {

    int mod=1e9+7;

    int solve(vector<vector<int>>&dp,int i,int k,int target){
        if(target==0 && i==0)return 1;
        if(target<=0 || i==0 )return 0;

        if(dp[i][target]!=-1)return dp[i][target];

        int count=0;

        for(int j=1;j<=k;j++){
            count=(count+solve(dp,i-1,k,target-j))%mod;
        }

        return dp[i][target]=count%mod;

    }


public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(dp,n,k,target);
    }
};