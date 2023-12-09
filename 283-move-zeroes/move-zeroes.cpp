class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return;
        int lo=0,hi=0;
       
        while(lo<n){
            if(nums[lo]==0){
                hi=lo;
                while(hi<n-1 && nums[hi]==0)
                hi++;
                swap(nums[lo],nums[hi]);
            }
            lo++;
        }
    }
};