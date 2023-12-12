class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=0,smaxi=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>=maxi){
            smaxi=maxi;
            maxi=nums[i];
            }else{
                smaxi=max(smaxi,nums[i]);
            }
        }
        return (smaxi-1)*(maxi-1);
    }
};