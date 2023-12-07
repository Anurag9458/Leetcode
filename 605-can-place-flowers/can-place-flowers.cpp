class Solution {
public:
    bool canPlaceFlowers(vector<int>& flower, int n) {
        int ans=0;
        int m=flower.size();
        if(n==0)return 1;
        if(m==1 && (!flower[0] && n==1) || (flower[0]  && n==0))return 1;
        else if(m==1 && n>1)return 0;
        if(!flower[0] && m>1 && !flower[1]){
            flower[0]=1;
            ans++;
        }
         if(!flower[m-1] && m>1 && !flower[m-2]){
            flower[m-1]=1;
            ans++;
        }
        for(int i=1;i<m-1;i++){
            if(!flower[i] && !flower[i-1] && !flower[i+1])
            {
                flower[i]=1;
                ans++;
            }
        }

        return ans>=n;
    }
};