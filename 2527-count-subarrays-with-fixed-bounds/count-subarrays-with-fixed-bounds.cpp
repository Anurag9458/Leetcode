#define ll long long 


class Solution {


public:
    long long countSubarrays(vector<int>& nums, int mink, int maxk) {
        ll ans=0;
        ll pmini=-1,j=-1,pmaxi=-1;
        ll n=nums.size();

        for(ll i=0;i<n;i++){
            if(nums[i]<mink || nums[i]>maxk){
                j=i;
            }
            if(nums[i]==mink){
                pmini=i;
            }
            if(nums[i]==maxk){
                pmaxi=i;
            }

            ans+=max((ll)0,min(pmini,pmaxi)-j);
        }


        return ans;

    }
};