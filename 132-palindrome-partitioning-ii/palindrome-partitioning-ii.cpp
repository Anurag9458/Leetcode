class Solution {

    int ans=1e9;

    bool ispalindrome(int lo,int hi,string &s){
        while(lo<=hi){
            if(s[lo++]!=s[hi--])return 0;
        }
        return 1;
    }

    int solve(int i,int n,string &s,vector<int>&dp){
        if(i==n){
            return 0;
        }

        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=1e9;

        for(int j=i;j<n;j++){
            if(ispalindrome(i,j,s)){
                int temp=1+solve(j+1,n,s,dp);
                ans=min(temp,ans);
            }
        }
        return dp[i]=ans;
    }

public:
    int minCut(string s) {
        int n=s.size();

        vector<int>dp(n,-1);

        return solve(0,n,s,dp)-1;
        
    }
};