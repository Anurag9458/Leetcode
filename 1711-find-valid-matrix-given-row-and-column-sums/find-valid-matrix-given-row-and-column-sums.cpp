class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& row, vector<int>& col) {
        int n=row.size(),m=col.size();
        vector<vector<int>>ans(n,vector<int>(m,0));

        int i=0,j=0;

        while(i<n && j<m){
            int temp=min(row[i],col[j]);
            row[i]-=temp;
            col[j]-=temp;

            ans[i][j]=temp;

            if(row[i]==0){
                i++;
            }

            if(col[j]==0){
                j++;
            }

        }

        return ans;
    }
};