class Solution {

    int mod=1e9+7;

    int solve(int i,int seat,string &s,vector<vector<int>>&dp,int n){
        if(i==n){
            if(seat==2)return 1;
            return 0;
        }

        if(dp[i][seat]!=-1)return dp[i][seat];

        int calls=0;
        if(seat==2){
        if(s[i]=='P'){
            calls+=solve(i+1,0,s,dp,n)%mod;
            calls+=solve(i+1,seat,s,dp,n)%mod;
        }
        else{
            calls+=solve(i+1,1,s,dp,n)%mod;  
        }
        }
         else
            calls+=solve(i+1,seat+(s[i]=='S'),s,dp,n)%mod;

        return dp[i][seat]=calls%mod;
    }


public:
    int numberOfWays(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(3,-1));
        return solve(0,0,s,dp,n);
    }
};