class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        int sum=0,ans=0;
        int n=nums.size();
        mp[0]=1;
        for(int i=0;i<n;i++){
            
            sum+=nums[i];
            ans+=mp[sum-k];
            mp[sum]++;
            
        }
        return ans;
    }
};