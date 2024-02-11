class Solution {

    int solve(int i,int j,int n,int m,vector<vector<int>>&grid,int sum){
        if(i>=n || j>=m || i<0 || j<0){
            return 0;
        }
        if(i==n-1){
            return sum;
        }
        sum+=grid[i][j];
        int left=solve(i+1,j-1,n,m,grid,sum);
        int bottom=solve(i+1,j,n,m,grid,sum);
        int right=solve(i+1,j+1,n,m,grid,sum);

        return max({left,right,bottom});

    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        
               int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        dp[0][0][n-1] = grid[0][0] + grid[0][n-1];

        int ans = 0;
        for(int i = 1; i < m; ++i) {
            for(int j = 0; j < n; ++j) { // robotA
                for(int k = j+1; k < n; ++k) { // robotB
                    for(int x = -1; x <= 1; ++x) { // x and y all possible combinations
                        for(int y = -1; y <= 1; ++y) {
                            int nj = j + x, nk = k + y;
                            if(nj >= 0 && nj < n && nk >= 0 && nk < n) {
                                int prev = dp[i-1][nj][nk];
                                if(prev != -1) {
                                    dp[i][j][k] = max(dp[i][j][k], prev + grid[i][j] + (j != k ? grid[i][k] : 0));
                                }
                            }
                        }
                    }
                    if(ans < dp[i][j][k]) ans = dp[i][j][k];
                }
            }
        }
        
        return ans;
    }
};