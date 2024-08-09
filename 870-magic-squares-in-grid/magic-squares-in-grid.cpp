class Solution {

bool isMagicSquare(const vector<vector<int>>& grid, int i, int j) {
    unordered_set<int> s;
    for (int x = i; x < i + 3; x++) {
        for (int y = j; y < j + 3; y++) {
            if (grid[x][y] < 1 || grid[x][y] > 9 || s.count(grid[x][y])) {
                return false;
            }
            s.insert(grid[x][y]);
        }
    }

    int sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2]; // Row 1
    for (int x = i + 1; x < i + 3; x++) {
        int rowSum = grid[x][j] + grid[x][j + 1] + grid[x][j + 2];
        if (rowSum != sum) {
            return false;
        }
    }

    for (int y = j; y < j + 3; y++) {
        int colSum = grid[i][y] + grid[i + 1][y] + grid[i + 2][y];
        if (colSum != sum) {
            return false;
        }
    }

    int diag1 = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
    int diag2 = grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j];
    return diag1 == sum && diag2 == sum;
}

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=0;
        for(int i=0;i<=n-3;i++){
            for(int j=0;j<=m-3;j++){
                if(isMagicSquare(grid,i,j)){
                    ans++;
                }
        }
        }

        return ans;
    }
};