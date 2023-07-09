class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = -1e5;
        int n = nums.size();
        int i = 0, j = 0;
        double sum = 0;
        while(j < k && j < n){
            sum += nums[j++];
        }
        ans = max(sum/k,ans);
        while(j < n){
            sum -= nums[i++];
            sum += nums[j++];
            ans = max(sum/k, ans);
        }
        return ans;
    }
};