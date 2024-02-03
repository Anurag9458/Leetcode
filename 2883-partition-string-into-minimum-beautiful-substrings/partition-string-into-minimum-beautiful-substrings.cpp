class Solution {

    bool check(string s){
        if(s[0]=='0'){
            return 0;
        }
        int temp=0;
        reverse(begin(s),end(s));
        int i=0;
        for(char c:s){
            if(c=='1'){
                temp+=pow(2,i);
            }
            i++;
        }
        
        float res=log(temp)/log(5);
        return res==floor(res);
    }


    int solve(int i,int n,string &s,vector<int>&dp){
        if(i==n){
            return 0;
        }
        int ans=1e9;
        if(dp[i]!=-1){
            return dp[i];
        }
        string temp;
        for(int j=i;j<n;j++){
            temp.push_back(s[j]);
            if(check(temp)){
                ans=min(ans,1+solve(j+1,n,s,dp));
            }
        }
        
        return dp[i]=ans;
    }

public:
    int minimumBeautifulSubstrings(string s) {
        int temp=0;
        for(char c:s){
            if(c=='1')temp++;
        }
        if(temp==0){
            return -1;
        }
        int n=s.size();

        vector<int>dp(n,-1);

        int ans=solve(0,n,s,dp);
        return ans==1e9?-1:ans;
    }
};