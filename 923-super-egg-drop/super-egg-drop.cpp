class Solution {


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
    int superEggDrop(int e, int n) {

        vector<vector<int>>dp(e+1,vector<int>(n+1,-1));

        for(int i=1;i<=e;i++){
            dp[i][0]=0;dp[i][1]=1;
        }

        for(int i=1;i<=n;i++){
            dp[1][i]=i;
        }

        for(int i=2;i<=e;i++){
            for(int j=2;j<=n;j++){
                int mini=1e9;
                int lo=1,hi=j;
                while(lo<=hi){
                    int mid=lo+(hi-lo)/2;
                    int left=dp[i-1][mid-1];
                    int right=dp[i][j-mid];
                    int temp=1+max(left,right);
                    if(left<right){
                        lo=mid+1;
                    }else{
                        hi=mid-1;
                    }
                    mini=min(temp,mini);
                }

                dp[i][j]=mini;
            }
        }


        return dp[e][n];
    }
};