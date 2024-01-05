class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        vector<int>ans;

        for(int i:nums){
            mp[i]++;
            if(mp[i]==2){
                ans.push_back(i);
            }
        }
        return ans;
    }
};