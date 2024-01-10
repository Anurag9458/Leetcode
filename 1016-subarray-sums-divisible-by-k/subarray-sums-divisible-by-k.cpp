class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
      int ans=0,n=nums.size();
      map<int,int>mp;
      mp[0]=1;
      int sum=0;
      for(int i=0;i<n;i++){
          sum+=nums[i];
          int rem=((sum%k)+k)%k;
          if(mp.count(rem)){
              ans+=mp[rem];
              mp[rem]++;
          }else{
              mp[rem]++;
          }
      }

      return ans;
    }
};