int dp[101][27][101][101];

class Solution {

    int solve(int i,char prev,int freq,string &s,int k,int &n){
        if(k<0)return 1e9;
        if(i>=n){
            return 0;
        }
        int temp=prev-'a';
        if(dp[i][temp][freq][k]!=-1){
            return dp[i][temp][freq][k];
        }

        int nottake=solve(i+1,prev,freq,s,k-1,n);
        int take=0,len=0;
        if(s[i]!=prev){
            take=1+solve(i+1,s[i],1,s,k,n);
        }else{
        if(freq==1 || freq==9 || freq==99){
            len++;
        }
        take=len+solve(i+1,prev,freq+1,s,k,n);
        }

        return dp[i][temp][freq][k]=min(take,nottake);
    }

public:
    int getLengthOfOptimalCompression(string s, int k) {
        
        int n=s.size();
       
        memset(dp,-1,sizeof(dp));
        return solve(0,'z'+1,0,s,k,n);     
        

    }
};