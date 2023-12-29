class Solution {

    int solve(int i,vector<int>&job,int &n,int d,vector<vector<int>>&dp){
        if(i>=n)return 0;
        if(d==1){
            return *max_element(begin(job)+i,end(job));
        }
        
        if(dp[i][d]!=-1){
            return dp[i][d];
        }
        int a=0,ans=1e9;

        for(int j=i;j<=n-d;j++){
            a=max({a,job[j]});
            int temp=solve(j+1,job,n,d-1,dp);
            ans=min(ans,a+temp);
        }
        if(ans==1e9)ans=-1;
        return dp[i][d]=ans;
    }

public:
    int minDifficulty(vector<int>& job, int d) {
        int n=job.size();
        if(n<d)return -1;
        if(d==1){
            return *max_element(begin(job),end(job));
        }
        if(d==n){
            return accumulate(begin(job),end(job),0);
        }
        vector<vector<int>>dp(n+1,vector<int>(d+1,-1));
        return solve(0,job,n,d,dp);
    }
};