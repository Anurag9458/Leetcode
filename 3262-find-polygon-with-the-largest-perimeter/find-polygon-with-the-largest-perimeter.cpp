class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        
        int n=nums.size();
        sort(begin(nums),end(nums));
        if(n==3){
            if(nums[0]+nums[1]>nums[2])
                return nums[0]+nums[1]+nums[2];
            return -1;
        }
        
        vector<long long>pre;
        pre.push_back(nums[0]);
        
        for(int i=1;i<n;i++)
            pre.push_back(pre.back()+nums[i]);
        
        for(int i=n-2;i>=0;i--){
            if(pre[i]>nums[i+1])return pre[i+1];
        }
        
        return -1;
    }
};