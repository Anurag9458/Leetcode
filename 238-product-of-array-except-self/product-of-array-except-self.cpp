class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>ans,pre,suff;

        pre.push_back(1);
        suff.push_back(1);

        for(int i=0;i<n;i++)
        pre.push_back(pre.back()*nums[i]);

        for(int i=n-1;i>=0;i--)
        suff.push_back(suff.back()*nums[i]);

        reverse(begin(suff),end(suff));

        // int mod=1e9+7;

        for(int i=0;i<n;i++){

            ans.push_back((pre[i]*suff[i+1]));

        }

        return ans;
    }
};