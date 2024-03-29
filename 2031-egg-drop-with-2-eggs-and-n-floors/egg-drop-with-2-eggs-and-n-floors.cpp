class Solution {

// int solve(int e,int f,vector<vector<int>>&dp){
//     if(f==0||f==1){
//         return f;
//     }
//     if(e==1){
//         return f;
//     }

//     if(dp[e][f]!=-1){
//         return dp[e][f];
//     }

//     int mini=1e9;

//     for(int i=1;i<=f;i++){
//         int temp=1+max(solve(e-1,i-1,dp),solve(e,f-i,dp));
//         mini=min(temp,mini);
//     }
//     return dp[e][f]=mini;
// }

  int solve(int k,int n,vector<vector<int>>&dp){
        if(n==0 || n==1){
            return n;
        }
        if(k==1){
            return n;
        }
        if(dp[k][n]!=-1){
            return dp[k][n];
        }
        int mini=1e9;
        for(int i=1;i<=n;i++){
            int temp=1+max(solve(k-1,i-1,dp),solve(k,n-i,dp));
            mini=min(mini,temp);
        }
        return dp[k][n]=mini;
    }


public:
    int twoEggDrop(int n) {
        vector<vector<int>>dp(3,vector<int>(n+1,-1));
        return solve(2,n,dp);
    }
};