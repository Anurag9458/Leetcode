class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int n=nums.size();
        // if(n==1 && nums[0]==val){nums.pop_back();return 0;}
        int lo=0,hi=n-1;
        while(hi>=lo && nums[hi]==val)hi--;
        if(hi<0)return 0;
        while(lo<=hi){
            if(nums[lo]==val){
                swap(nums[lo],nums[hi]);
                while(hi>lo && nums[hi]==val)hi--;
            }
            lo++;
        }
        return hi+1;
    }
};