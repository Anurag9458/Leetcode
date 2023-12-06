class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& mat) {
    int n=mat.size(),m=mat[0].size();
    if(mat[0][0]==1)return -1;
    vector<vector<int>>dis(n,vector<int>(m,1e9));
    dis[0][0]=1;
    int row[8]={-1,1,0,0,-1,1,-1,1},col[8]={0,0,-1,1,-1,1,1,-1};

    set<pair<int,pair<int,int>>>st;
    st.insert({1,{0,0}});

    while(!st.empty()){
        auto it=*st.begin();
        int dt=it.first,i=it.second.first,j=it.second.second;
        st.erase(it);
        for(int a=0;a<8;a++){
            int ni=i+row[a],nj=j+col[a];
            if(ni>=0 && ni<n && nj>=0 && nj<m && !mat[ni][nj]){
                if(dt+1<dis[ni][nj]){
                dis[ni][nj]=dt+1;
                st.insert({dt + 1, {ni, nj}});
                }
            }
        }

    }

    if(dis[n-1][m-1]==1e9)
    return -1;
    return dis[n-1][m-1];
    }
};