class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        
        int n=mat.size(),m=mat[0].size();
        vector<int>vr(n,0),vc(m,0);

        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<m;j++){
                if(mat[i][j])count++;
            }
            vr[i]=(count);
        }

        for(int i=0;i<m;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(mat[j][i])count++;
            }
            vc[i]=(count);
        }

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] && vr[i]==1 && vc[j]==1)ans++;
            }
        }

        return ans;

    }
};