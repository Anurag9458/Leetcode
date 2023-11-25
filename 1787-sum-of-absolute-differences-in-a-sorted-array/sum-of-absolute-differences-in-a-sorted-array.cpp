class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        vector<int>pre,suf;
        pre.push_back(0);
        for(int i:nums)
        pre.push_back(pre.back()+i);
        int sum=0;
        for(int i=n-1;i>=0;i--)
       { sum+=nums[i];
        suf.push_back(sum);}
        reverse(begin(suf),end(suf));
        // cout<<suf[0]<<endl;
        for(int i=0;i<n;i++){
            int temp = abs(suf[i] - nums[i]*(n-i)) + abs(pre[i]-nums[i]*(i));
            ans.push_back(temp);
        }
        return ans;
    }
};