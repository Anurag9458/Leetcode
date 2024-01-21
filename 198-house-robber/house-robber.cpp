class Solution {

    int solve(int i,vector<int>&nums,vector<int>&dp){
        if(i==0){
            return nums[i];
        }
        if(i<=0){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int take=nums[i]+solve(i-2,nums,dp);
        int nottake=solve(i-1,nums,dp);
        return dp[i]=max(take,nottake);
    }

public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(n-1,nums,dp);
    }
};