class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int mini1=1e9,mini2=1e9;
        int n=prices.size();
        for(int i=0;i<n;i++){
            if(prices[i]<=mini1){
                mini2=mini1;
                mini1=prices[i];
            }else if(prices[i]!=mini1 && prices[i]<mini2){
                mini2=prices[i];
            }

        }

        if(mini1+mini2<=money){
            return money-mini1-mini2;
        }
        return money;

    }
};