class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dis(n,vector<int>(n,1e9));
        set<pair<int,pair<int,int>>>st;
        int ans=1e9;
        for(int i=0;i<n;i++){
            st.insert({matrix[0][i],{0,i}});
            dis[0][i]=matrix[0][i];
        }

        int row[3]={1,1,1},col[3]={-1,0,1};
        while(!st.empty()){
            auto it=*st.begin();
            st.erase(it);
            int i=it.second.first,j=it.second.second,d=it.first;
            if(i==n-1){
                ans=min(ans,d);
            }
            for(int a=0;a<3;a++){
                int ni=i+row[a],nj=j+col[a];
                if(ni>=0 && ni<n && nj>=0 && nj<n){
                    if(d+matrix[ni][nj]<dis[ni][nj]){
                    dis[ni][nj]=d+matrix[ni][nj];
                    st.insert({d+matrix[ni][nj],{ni,nj}});
                    
                    }
                }
            }
        }
        return ans;
    }
};