class Solution {

    int n;
    int wd;
    int dp[1001][1001];

    int solve(int i,int w,vector<vector<int>>&books,int maxi){
        if(i==n){
            return maxi;
        }

        int h=books[i][1];
        int b=books[i][0];
        if(dp[i][w]!=-1){
            return dp[i][w];
        }
        int take=1e9;
        if(w>=b)
        take=solve(i+1,w-b,books,max(maxi,h));
        int skip=maxi+solve(i+1,wd-b,books,h);

        return dp[i][w]=min(skip,take);
    }


public:
    int minHeightShelves(vector<vector<int>>& books, int w) {
        int maxi=0;
        n=books.size();
        wd=w;
        memset(dp,-1,sizeof(dp));
        return solve(0,w,books,maxi);
    }
};