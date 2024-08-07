class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();

        if(n<=4){
            return 0;
        }

        sort(begin(nums),end(nums));

        int ans=INT_MAX;

        for(int i=0,j=n-4;i<4;i++,j++){
            ans=min(ans,(nums[j]-nums[i]));
        }

        return ans;

    }
};