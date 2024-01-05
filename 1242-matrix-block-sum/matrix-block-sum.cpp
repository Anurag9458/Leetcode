class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {

    vector<vector<int>>pre;
    int n=mat.size(),m=mat[0].size();
    
    for(auto it:mat){
        vector<int>temp;

        for(int i:it){
            if(temp.empty()){
                temp.push_back(i);
            }else{
                temp.push_back(temp.back()+i);
            }
        }

        pre.push_back(temp);

    }

    vector<vector<int>>ans(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int nil=max(0,i-k),nir=min(i+k,n-1),njl=max(0,j-k),njr=min(j+k,m-1);
            int sum=0;
            for(int a=nil;a<=nir;a++){
                // for(int b=njl;b<=njr;b++){
                    sum+=pre[a][njr];
                    if(njl-1>=0){
                        sum-=pre[a][njl-1];
                    }
                // }
            }
            ans[i][j]=sum;

        }
    }
    return ans;
    }
};