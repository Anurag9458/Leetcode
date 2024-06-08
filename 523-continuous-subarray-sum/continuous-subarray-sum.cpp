class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size(),temp=0,sum=0;
       
        map<int,int>mp;
        //  mp[0]++;
        for(int i=0;i<n;i++){
            sum=(sum+nums[i])%k;
            if(mp.count(sum)){
                return true;
            }
            mp[temp]++;
            temp=sum;
        }

        return 0;
    }
};