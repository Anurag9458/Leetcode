class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        int sum=0,ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[sum]++;
            sum+=nums[i];
            if(mp.count(sum-k))ans+=mp[sum-k];
        }
        return ans;
    }
};