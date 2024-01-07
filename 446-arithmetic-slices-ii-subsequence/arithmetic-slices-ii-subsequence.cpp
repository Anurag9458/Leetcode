#define ll long long int
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        ll n=nums.size();
        map<ll,ll>mp[n];
        ll ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                ll diff=(ll)nums[i]-(ll)nums[j];
                ll count=0;
                if(mp[j].count(diff)){
                    count=mp[j][diff];
                }
                mp[i][diff]+=count+1;
                ans+=count;
            }
        }
        return ans;
    }
};