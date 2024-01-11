class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       int ans=0;
       int n=nums.size();
       map<int,int>mp;
       for(int &i:nums){
           if(i&1)i=1;
           else i=0;
       }
       mp[0]=1;
       int count=0,sum=0;
       for(int i:nums){
            sum+=i;
            count+=mp[sum-k];
            // cout<<sum-k<<" "<<mp[sum-k]<<endl;
            mp[sum]++;
       }
        return count;
    }
};