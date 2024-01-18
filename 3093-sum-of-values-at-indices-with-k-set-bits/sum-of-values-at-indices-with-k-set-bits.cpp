class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        
        int ans=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            int count=__builtin_popcount(i);
            if(count==k){
                ans+=nums[i];
            }
        }

        return ans;
    }
};