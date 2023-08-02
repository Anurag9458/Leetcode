class Solution {
    void permutations(vector<int>&nums,vector<vector<int>>&ans,int n,int index)
    {
        if(index==n)
        {
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<n;i++)
        {
            swap(nums[i],nums[index]);
            permutations(nums,ans,n,index+1);
            swap(nums[i],nums[index]);
        }
        
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        permutations(nums,ans,n,0);
        return ans;
    }
};