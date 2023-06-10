class Solution {

int solve(int i,int prev,vector<int>&nums,vector<vector<int>>&dp)
{
    if(i==nums.size())
    {
        return 0;
    }

    if(dp[i][prev+1]!=-1)return dp[i][prev+1];
    int take=0,nottake=0;

    if(prev==-1 || nums[i]>nums[prev])take=1+solve(i+1,i,nums,dp);
    nottake=solve(i+1,prev,nums,dp);

    return dp[i][prev+1]=max(take,nottake);
}

public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int prev=i-1;prev>=-1;prev--)
            {
                int take=0,nottake=0;
                if(prev==-1 || nums[prev]<nums[i])
                take=1+dp[i+1][i+1];
                nottake=dp[i+1][prev+1];
                dp[i][prev+1]=max(take,nottake);
            }
        }
       return dp[0][0];
    }
};