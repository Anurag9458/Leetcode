class Solution {
public:
    int longestSubarray(vector<int>& nums, int l) {
        int n=nums.size();
        using p=pair<int,int>;
        int ans=0,i=0,j=0;

        priority_queue<p,vector<p>>maxp;
        priority_queue<p,vector<p>,greater<p>>minp;

        while(j<n){
        
            maxp.push({nums[j],j});
            minp.push({nums[j],j});

            while(maxp.top().first-minp.top().first>l){
                i=min(maxp.top().second,minp.top().second)+1;

                while(maxp.top().second<i){
                    maxp.pop();
                }

                while(minp.top().second<i){
                    minp.pop();
                }
            }

            ans=max(ans,j-i+1);

            j++;

        }


        return ans;
    }
};