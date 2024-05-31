class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        using ll=long long;
       ll b1=0,b2=0;

        ll n=nums.size();
        ll right=0,xorr=0;
        for(ll i:nums){
            xorr^=i;
        }

        right=(xorr&(~(xorr-1)));

        for(ll i=0;i<n;i++){
            if(nums[i]&right){
                b1^=nums[i];
            }else{
                b2^=nums[i];
            }
        }
        vector<int>v;
        v.push_back(b1);
        v.push_back(b2);

        return v;
    }
};