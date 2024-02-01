class Solution {
    int dp[2001][2001];
    unordered_map<int,int>mp;
    bool solve(int i,int prevjump,int n,vector<int>&stones){
        if(i==n-1){
            return 1;
        }

        if(dp[i][prevjump]!=-1){
            return dp[i][prevjump];
        }

        int res=0;
        for(int j=prevjump-1;j<=prevjump+1;j++){
            if(j>0){
                int ni=stones[i]+j;
                if(mp.count(ni)){
                    res=res||solve(mp[ni],j,n,stones);
                }
            }
        }
        return dp[i][prevjump]=res;
    }


public:
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        if(stones[1]-stones[0]>1){
            return 0;
        }
        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }
        memset(dp,-1,sizeof(dp));
        return solve(mp[0],0,n,stones);
    }
};