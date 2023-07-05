class Solution {

    int solve(vector<int>& nums,int x){
        int maxi = 0;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(i == x){
                continue;
            }
            if(nums[i] == 1){
                count++;
                maxi = max(maxi, count);
            }
            else{
                count = 0;
            }
        }
        return maxi;
    }

public:
    int n;
    int longestSubarray(vector<int>& nums) {
        n = nums.size();
        int count = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            
            if(nums[i] == 0){
                count++;
                ans  = max(ans, solve(nums,i));
            }
            
        }
        
        if(count == 0){
            return n - 1;
        }
        return ans;
    }
};