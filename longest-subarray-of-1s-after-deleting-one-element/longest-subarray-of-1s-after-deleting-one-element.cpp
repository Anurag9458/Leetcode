class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int i = 0,count = 0,maxi = 0, last = -1 , curr = -1;

        for(int j = 0; j < n; j++){
            if(nums[j] == 0){
                last = curr;
                curr = j;
                count++;
            }
            if(count > 1){
                i = last + 1;
            }
            maxi = max(maxi, j-i);
        }

        return maxi;
    }
};