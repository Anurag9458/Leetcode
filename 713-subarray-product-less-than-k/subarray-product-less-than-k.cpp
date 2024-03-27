class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0;
        if(k<=1){
            return 0;
        }
        int i=0,j=0;
        int n=nums.size();
        long long pro=1;
       
       while(i<n){
        pro*=nums[i];
        while(pro>=k){
            pro/=nums[j];
            j++;
        }
        ans+=i-j+1;
        i++;
       }


        return ans;

    }
};