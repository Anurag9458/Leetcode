class Solution {

    int solve(vector<int>&nums,int k){
        map<int,int>mp;

        int i=0,j=0,count=0;
        int n=nums.size();


        while(i<n){
            mp[nums[i]]++;

            while(mp.size()>k){
                mp[nums[j]]--;
                if(mp[nums[j]]==0){
                    mp.erase(nums[j]);
                }
                j++;
            }

            count+=i-j+1;
            i++;
        }

        return count;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};