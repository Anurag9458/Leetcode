class Solution {

    int dp[101];    

    int solve(int i,vector<int>&nums){
        if(i==0){
            return nums[i];
        }
        if(i<0){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int take=nums[i]+solve(i-2,nums);
        int nottake=solve(i-1,nums);
        return dp[i]=max(take,nottake);
    }


public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(n-1,nums);
    }
};