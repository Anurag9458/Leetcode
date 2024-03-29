class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n=nums.size(),left=INT_MAX,mid=INT_MAX;

        for(int i=0;i<n;i++){
            
            if(nums[i]<left)left=nums[i];
            else if(nums[i]>left && nums[i]<mid)mid=nums[i];
            else if(nums[i]>mid)return 1;

        }
        return 0;
    }
};