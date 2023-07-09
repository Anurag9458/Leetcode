class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int n = nums.size();
        if(n == 1)return 0;
        map<int,int> mp;
        while(j <= k && j < n){
            if(mp.count(nums[j])){
                return 1;
            }
            mp[nums[j]]++;
            j++;
        }
        while(j < n){
            mp[nums[i]]--;
            if(mp[nums[i]] == 0){
                mp.erase(nums[i]);
            }
            i++;
            if(mp.count(nums[j])){
                return 1;
            }
            mp[nums[j]]++;
            j++;
        }
        return 0;
    }
};