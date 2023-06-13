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
        int ans=1;
        vector<int>temp;
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(temp.back()<nums[i])
            {temp.push_back(nums[i]);ans++;}
            else
            {
                int ind=lower_bound(begin(temp),end(temp),nums[i])-temp.begin();
                temp[ind]=nums[i];
            }
        }
        return ans;
    }
};