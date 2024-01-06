class Solution {

    bool solve(int i,int n,string s,map<string,int>&mp,vector<int>&dp){
        if(i>=n){
            return 1;
        }

        // if(mp.count(s.substr(i,n-i))){
        //     return 1;
        // }
       
        if(dp[i]!=-1){
            return dp[i];
        }
        for(int j=0;j<n;j++){
            string temp=s.substr(i,j+1);
            if(mp.count(temp)){
                if(solve(i+j+1,n,s,mp,dp))
                return dp[i]=1;
            }
        }
        return dp[i]=0;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string,int>mp;
        int n=s.size();
        for(string a:wordDict){
            mp[a]++;
        }
        string temp;
        vector<int>dp(n,-1);
        return solve(0,n,s,mp,dp);
    }
};