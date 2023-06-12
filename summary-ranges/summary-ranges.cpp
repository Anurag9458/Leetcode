class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;

        int n=nums.size();
        if(n==0)return ans;

        for(int i=0;i<nums.size();i++)
        {
            string temp;
            //We just insert the element as it is 
            temp+=to_string(nums[i]);
            
            //We are checking for range ,whether this element will make range forward or not 
            if(i+1<nums.size() && nums[i+1]==nums[i]+1)
            {
                while(i+1<nums.size() && nums[i+1]==nums[i]+1)
                i++;

                //Here we found that there is a range,so we insert a range in our ans
                temp+="->";
                temp+=to_string(nums[i]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};