class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum=0,maxi_sum=INT_MIN,n=nums.size();
        for(int i=0;i<n;i++)
        {
            curr_sum=max(nums[i],curr_sum+nums[i]);
            maxi_sum=max(maxi_sum,curr_sum);
        }
        return maxi_sum;
    }
};