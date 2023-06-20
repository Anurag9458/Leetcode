class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n  = nums.size();
        vector<int>ans(n,-1);
        if(2*k+1 > n)
        {
             vector<int>temp(n,-1);
             return temp;
        }
        vector<long long> prefix(n+1);
        for(int i = 0;i < n;i++)
        {
            prefix[i+1] = nums[i] + prefix[i];
        }
        
        
        for(int i = k; i < n-k;i++)
        {
            
            int left = i-k, right = i+k;
            long long sum = prefix[right + 1] - prefix[left];
            int av =  sum / (2*k + 1);
            ans[i] = av;
        }
        
        return ans;
    }
};