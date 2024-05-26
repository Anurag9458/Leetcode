class Solution {

    int mod=1e9+7;
    int dp[100001][2][3];

    int solve(int n,int a,int l){
        if(a>1 || l>2){
            return 0;
        }
        if(n==0){
            return 1;
        }
        
        if(dp[n][a][l]!=-1){
            return dp[n][a][l];
        }
        // cout<<n<<" "; 
        int ab=solve(n-1,a+1,0)%mod;
        int la=solve(n-1,a,l+1)%mod;
        int p=solve(n-1,a,0)%mod;
        

        return dp[n][a][l]=((ab+la)%mod+p)%mod;

    }

public:
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,0,0);
    }
};