class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mp;
        int ans=0;
        int j=0;

        for(int i=0;i<n;i++){
            while(j<n && mp[nums[j]]+1<=k)mp[nums[j++]]++;
            ans=max(ans,j-i);
            mp[nums[i]]--;
        }

        
        return ans;
    }
};