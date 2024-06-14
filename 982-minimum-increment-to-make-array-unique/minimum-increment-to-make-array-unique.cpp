class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(begin(nums),end(nums));
        // map<int,int>mp;
        int n=nums.size();
        int ans=0;
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1]){
                int temp=nums[i-1]+1-nums[i];
                ans+=temp;
                nums[i]=nums[i-1]+1;
            }
        }
        return ans;
    }
};