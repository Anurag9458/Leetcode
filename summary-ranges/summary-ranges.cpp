class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        int n=nums.size();
        if(n==0)return ans;
        for(int i=0;i<nums.size();i++)
        {
            string temp;
            temp+=to_string(nums[i]);
            if(i+1<nums.size() && nums[i+1]==nums[i]+1)
            {
                while(i+1<nums.size() && nums[i+1]==nums[i]+1)
                i++;
                temp+="->";
                temp+=to_string(nums[i]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};