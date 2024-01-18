class Solution {
    map<string,int>mp;
    int dp[52];
public:

    int solve(int i,int &n,string &s){
        if(i>=n){
            return 0;
        }

        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=n,curr;
        string temp;
        for(int j=i;j<n;j++){
            temp.push_back(s[j]);
            if(!mp.count(temp)){
                curr=temp.length();
            }else{
                curr=0;
            }
            int remain=solve(j+1,n,s);
            ans=min(remain+curr,ans);
        }
        return dp[i]=ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        
    for(string s:dictionary){
        mp[s]++;
    }
    memset(dp,-1,sizeof(dp));
    int n=s.size();
    int a=solve(0,n,s);
    return a;
    }
};