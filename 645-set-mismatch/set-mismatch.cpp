class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int sum=0,a,n=nums.size();
        map<int,int>mp;
        for(int i:nums){
            sum+=i;
            if(mp.count(i))a=i;
            else mp[i]++;
        }
        int total=n*(n+1)/2;
        return {a,a+(total-sum)};
    }
};