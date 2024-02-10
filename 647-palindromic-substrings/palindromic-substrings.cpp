class Solution {

    bool check(string s){
        int lo=0,hi=s.size()-1;
        while(lo<=hi){
            if(s[lo]!=s[hi]){
                return 0;
            }
            lo++;hi--;
        }
        return 1;
    }

    int ans=0; 

    void solve(int i,int n,string &s){
        if(i==n){
            return;
        }
        string temp;
        for(int j=i;j<n;j++){
            temp.push_back(s[j]);
            // cout<<temp<<" ";
            if(check(temp)){
                ans++;    
            }else{
                break;
            }    
        }
        solve(i+1,n,s);
    }

public:
    int countSubstrings(string s) {
     int n=s.size();
     if(n==1){
         return 1;
     }

     vector<vector<int>>dp(n,vector<int>(n,0));

     for(int g=0;g<n;g++){
         for(int i=0,j=g;j<n;j++,i++){
             if(g==0){
                 dp[i][j]=1;
             }else if(g==1){
                 if(s[i]==s[j]){
                     dp[i][j]=1;
                 }else{
                     dp[i][j]=0;
                 }
             }else{
                 if(s[i]==s[j] && dp[i+1][j-1]){
                     dp[i][j]=1;
                 }else{
                     dp[i][j]=0;
                 }
             }

         }
     }

     int ans=0;

     for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
             if(dp[i][j]){
                 ans++;
             }
         }
     }

     return ans;

    }
};