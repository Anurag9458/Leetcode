class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int sum = 0, ans = 1e9;
        while(j < n){
            sum += nums[j];
            while(sum >= t){
                ans = min(ans, j - i + 1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        if(ans == 1e9)return 0;
        return ans;
    }
};