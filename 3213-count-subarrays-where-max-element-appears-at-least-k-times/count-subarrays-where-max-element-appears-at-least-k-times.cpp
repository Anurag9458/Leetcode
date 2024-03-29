class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
    long long count = 0;
    int n = nums.size();
    int maxi = *max_element(nums.begin(), nums.end());

    int j = 0;
    int maxCount = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] == maxi)
            maxCount++;

        while (maxCount >= k) {
            count += n - i;
            if (nums[j] == maxi)
                maxCount--;
            j++;
        }
    }

    return count;
    }
};