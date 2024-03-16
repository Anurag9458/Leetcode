class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int ans=0,sum=0;
        for(int &i:nums){
            if(!i)i=-1;
        }

        map<int,int>mp;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==0){
                ans=i+1;
            }
            if(mp.count(sum)){
                ans=max(ans,i-mp[sum]);
            }else{
                mp[sum]=i;
            }
        }
        return ans;
    }
};