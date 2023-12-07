class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(begin(coins),end(coins));
        int n=coins.size();

        int maxi=0,sum=0,i=0;

        while(maxi<target){
            if(i<n && coins[i]<=maxi+1)
            {
                maxi+=coins[i];
                i++;
            }else{
                maxi+=maxi+1;
                sum++;
            }
        }

        return sum;
    }
};