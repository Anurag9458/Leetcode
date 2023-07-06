class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
        int  n = nums.size();
        int ans = n+1,sum = 0, j = 0, i = 0;
        while(j<n){

            sum += nums[j];
            while(sum >= t){
                ans = min(ans , j - i + 1);
                sum -= nums[i];
                i++;
                
            }
            j++;

        }
        if(ans == n+1){
            return 0;
        }
        return ans;
    }
};