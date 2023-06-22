class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int>prev(2,0),curr(2,0);
        for(int i=n-1;i>=0;i--)
        {
            curr[1]=max(-prices[i]+prev[0],prev[1]);
            curr[0]=max(prices[i]-fee+prev[1],prev[0]);
            prev=curr;
        }
        return prev[1];
    }
};