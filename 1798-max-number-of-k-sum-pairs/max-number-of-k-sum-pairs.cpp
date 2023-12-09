class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int lo=0,hi=n-1;
        sort(begin(nums),end(nums));
        int count=0;
        while(lo<hi){
            if(nums[lo]+nums[hi]==k){
                count++;
                lo++;
                hi--;
            }else if(nums[lo]+nums[hi]<k){
                lo++;
            }else{
                hi--;
            }
        }
        return count;
    }
};