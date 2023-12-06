class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& arr) {
        
        int n=arr.size(),m=arr[0].size();
        vector<vector<int>>diff(n,vector<int>(m,1e9));
        diff[0][0]=0;
        set<pair<int,pair<int,int>>>st;
        st.insert({0,{0,0}});

        int row[4]={-1,1,0,0},col[4]={0,0,-1,1};

        while(!st.empty()){
            auto it=*st.begin();
            st.erase(it);
            int d=it.first,i=it.second.first,j=it.second.second;

            for(int a=0;a<4;a++)
            {
                int ni=i+row[a],nj=j+col[a];
                if(ni>=0 && ni<n && nj>=0 && nj<m ){
                    int nd=abs(arr[i][j]-arr[ni][nj]);
                    nd=max(nd,d);
                    if(nd<diff[ni][nj])
                    {
                        diff[ni][nj]=nd;
                        st.insert({nd,{ni,nj}});
                    }
                }
            }
        }
        if(diff[n-1][m-1]==1e9)return 0;
        return diff[n-1][m-1];
    }
};